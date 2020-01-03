/*
 * osci_transceiver.c
 *
 *  Created on: 24. 12. 2019
 *      Author: dot
 */

#include "osci_transceiver.h"
#include "osci_channel_state_machine.h"

void Gather_data(Osci_Transceiver* ts)
{
	// Make sure dataframe has the start word
	ts->sendingBuffer.start_word = OSCI_DATA_START_WORD;

	// Copy last complete measurement
	ts->sendingBuffer.xChannel = ts->x_channel_state_machine->measurement;
	ts->sendingBuffer.yChannel = ts->y_channel_state_machine->measurement;
}

void Transform_data(Osci_Transceiver* ts)
{
	OSCI_transform_apply(&ts->sendingBuffer, ts->x_channel_state_machine->params, ts->y_channel_state_machine->params);
}

void Send_data(Osci_Transceiver* ts)
{
	if (LL_DMA_IsEnabledChannel(ts->dma, ts->dmaTransmissionChannel)) // Do not do anything if data is still being sent
	{
		OSCI_error_notify("new data send skip");
		return;
	};

	LL_DMA_SetDataLength(ts->dma, ts->dmaTransmissionChannel, sizeof(Osci_DataFrame));
	LL_DMA_SetMemoryAddress(ts->dma, ts->dmaTransmissionChannel, (uint32_t)&ts->sendingBuffer);
	LL_DMA_EnableChannel(ts->dma, ts->dmaTransmissionChannel);
}

void Received_callback(Osci_Application* app)
{
	app->transceiver.receiveCompleteBuffer = app->transceiver.recveiveBuffer;
	app->transceiver.events.received_settings = TRUE;
}

void Sent_callback(Osci_Application* app)
{
	LL_DMA_DisableChannel(app->transceiver.dma, app->transceiver.dmaTransmissionChannel);
}

void Configure_usart(Osci_Transceiver* ts)
{
	// Configure USART channels, set buffer addresses etc.
	LL_USART_Disable(ts->usart);

	// Channel 6 (settings reading)
	LL_DMA_SetPeriphAddress(ts->dma, ts->dmaReceiverChannel, LL_USART_DMA_GetRegAddr(ts->usart, LL_USART_DMA_REG_DATA_RECEIVE));
	LL_DMA_SetMemoryAddress(ts->dma, ts->dmaReceiverChannel, (uint32_t)&ts->recveiveBuffer);

	LL_DMA_SetDataLength(ts->dma, ts->dmaReceiverChannel, sizeof(Osci_Settings));
	LL_DMA_EnableIT_TC(ts->dma, ts->dmaReceiverChannel);
	LL_DMA_EnableIT_TE(ts->dma, ts->dmaReceiverChannel);
	LL_USART_EnableDMAReq_RX(ts->usart);

	// Channel 7 (data writing)
	LL_DMA_SetPeriphAddress(ts->dma, ts->dmaTransmissionChannel, LL_USART_DMA_GetRegAddr(ts->usart, LL_USART_DMA_REG_DATA_TRANSMIT));
	//LL_DMA_SetMemoryAddress(DMA1, LL_DMA_CHANNEL_7, (uint32_t)&osci_dataframe_current);
	//LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_7, sizeof(Osci_DataFrame));

	LL_DMA_EnableIT_TE(ts->dma, ts->dmaTransmissionChannel);
	LL_DMA_EnableIT_TC(ts->dma, ts->dmaTransmissionChannel);
	LL_USART_EnableDMAReq_TX(ts->usart);

	LL_USART_Enable(ts->usart);
}

void Clear_events_ts(Osci_Transceiver* ts)
{
	ts->events.received_settings = FALSE;
	ts->events.send_requested = FALSE;
}

void OSCI_transceiver_init(Osci_Transceiver* ts, USART_TypeDef* usart, DMA_TypeDef* dma, uint32_t dmaReceiverChannel, uint32_t dmaTransmissionChannel, Osci_ChannelStateMachine* x_channel_state_machine, Osci_ChannelStateMachine* y_channel_state_machine)
{
	ts->usart = usart;
	ts->dma = dma;
	ts->dmaReceiverChannel = dmaReceiverChannel;
	ts->dmaTransmissionChannel = dmaTransmissionChannel;
	ts->x_channel_state_machine = x_channel_state_machine;
	ts->y_channel_state_machine = y_channel_state_machine;

	// Configure USART channels, set buffer addresses etc.
	Configure_usart(ts);

	// This unfortunately has to be set manually.
	osci_transceiver_received_callback = &Received_callback;
	osci_transceiver_sent_callback = &Sent_callback;

	// Fill in default settings (offsets, sensitivity, ...).
	OSCI_configurator_config_defaults_ts(ts);
	Clear_events_ts(ts);

	// Enable DMA channel for receiving new settings.
	LL_DMA_EnableChannel(ts->dma, ts->dmaReceiverChannel);

	ts->state = OSCI_TRANSCEIVER_STATE_IDLE;
}

void Send_shutdown_event(Osci_Transceiver* ts)
{
	if(ts->receiveCompleteBuffer.doMeasurement & OSCI_SETTINGS_DOMEASUREMENT_X)
		ts->x_channel_state_machine->events.shutdown = TRUE;

	if(ts->receiveCompleteBuffer.doMeasurement & OSCI_SETTINGS_DOMEASUREMENT_Y)
		ts->y_channel_state_machine->events.shutdown = TRUE;
}

void Switch_to_reconfiguring_after_shutdown(Osci_Transceiver* ts)
{
	switch(ts->receiveCompleteBuffer.doMeasurement)
	{
		case (OSCI_SETTINGS_DOMEASUREMENT_X | OSCI_SETTINGS_DOMEASUREMENT_Y):
		{
			if(ts->x_channel_state_machine->state == OSCI_CHANNEL_STATE_SHUTDOWN && ts->y_channel_state_machine->state == OSCI_CHANNEL_STATE_SHUTDOWN)
				ts->state = OSCI_TRANSCEIVER_STATE_RECONFIGURING_CHANNELS;
			break;
		}
		case OSCI_SETTINGS_DOMEASUREMENT_X:
		{
			if(ts->x_channel_state_machine->state == OSCI_CHANNEL_STATE_SHUTDOWN)
				ts->state = OSCI_TRANSCEIVER_STATE_RECONFIGURING_CHANNELS;
			break;
		}
		case OSCI_SETTINGS_DOMEASUREMENT_Y:
		{
			if(ts->y_channel_state_machine->state == OSCI_CHANNEL_STATE_SHUTDOWN )
				ts->state = OSCI_TRANSCEIVER_STATE_RECONFIGURING_CHANNELS;
			break;
		}
	}
}

void Reconfigure_channels(Osci_Transceiver* ts)
{
	Osci_Settings settingsCopy = ts->receiveCompleteBuffer;
	OSCI_configurator_recalculate_parameters(ts, &settingsCopy);
	OSCI_configurator_switch_relays(ts, &settingsCopy);

	OSCI_configurator_distribute_settings(ts, &settingsCopy);
}

void Start_monitoring(Osci_Transceiver* ts)
{
	if(ts->receiveCompleteBuffer.doMeasurement & OSCI_SETTINGS_DOMEASUREMENT_X)
		ts->x_channel_state_machine->events.start_monitoring = TRUE;

	if(ts->receiveCompleteBuffer.doMeasurement & OSCI_SETTINGS_DOMEASUREMENT_Y)
		ts->y_channel_state_machine->events.start_monitoring = TRUE;
}

void OSCI_transceiver_update(Osci_Transceiver* ts)
{
	switch(ts->state)
	{
		case OSCI_TRANSCEIVER_STATE_IDLE:
		{
			if (ts->events.received_settings)
			{
				if(ts->receiveCompleteBuffer.doMeasurement)
				{
					ts->state = OSCI_TRANSCEIVER_STATE_SHUTTING_DOWN_CHANNELS;
				}
				else
				{
					Reconfigure_channels(ts);
					ts->state = OSCI_TRANSCEIVER_STATE_GATHERING_TRANSFORMING_AND_SENDING;
				}

				ts->events.received_settings = FALSE;
			}

			if (ts->events.send_requested)
			{
				ts->state = OSCI_TRANSCEIVER_STATE_GATHERING_TRANSFORMING_AND_SENDING;
				ts->events.send_requested = FALSE;
			}
			break;
		}
		case OSCI_TRANSCEIVER_STATE_SHUTTING_DOWN_CHANNELS:
		{
			Send_shutdown_event(ts);
			ts->state = OSCI_TRANSCEIVER_STATE_WAITING_FOR_CHANNELS_TO_SHUTDOWN;
			break;
		}
		case OSCI_TRANSCEIVER_STATE_WAITING_FOR_CHANNELS_TO_SHUTDOWN:
		{
			Switch_to_reconfiguring_after_shutdown(ts);
			break;
		}
		case OSCI_TRANSCEIVER_STATE_RECONFIGURING_CHANNELS:
		{
			Reconfigure_channels(ts);
			ts->state = OSCI_TRANSCEIVER_STATE_STARTING_CHANNELS;
			break;
		}
		case OSCI_TRANSCEIVER_STATE_STARTING_CHANNELS:
		{
			Start_monitoring(ts);
			ts->state = OSCI_TRANSCEIVER_STATE_IDLE;
			break;
		}
		case OSCI_TRANSCEIVER_STATE_GATHERING_TRANSFORMING_AND_SENDING:
		{
			Gather_data(ts);
			Transform_data(ts);
			Send_data(ts);
			ts->state = OSCI_TRANSCEIVER_STATE_IDLE;
			break;
		}
	}
}

void transition(uint32_t flag, uint32_t compare, void (*transition_call) (void*), void* data_ref)
{
	if(flag & compare)
		transition_call(data_ref);
}
