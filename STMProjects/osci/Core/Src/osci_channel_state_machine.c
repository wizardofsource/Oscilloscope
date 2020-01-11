/*
 * osci_channel_state_machine.h
 *
 *  Created on: 24. 12. 2019
 *      Author: dot
 */
#include "osci_channel_state_machine.h"

void OSCI_channel_init(Osci_ChannelStateMachine* csm, TIM_TypeDef* timer, TIM_TypeDef* holdOffTimer, DMA_TypeDef* dma, uint32_t dmaChannel, ADC_TypeDef* adc, uint32_t awd, Measurement_complete_callback measurement_complete_callback, Awd_threshold_callback awd_threshold_callback, ADC_callback holdOffTimerCallback, Osci_Transceiver* transceiver, uint16_t channelOpcode)
{
	csm->timer = timer;
	csm->holdOffTimer = holdOffTimer;
	csm->adc = adc;
	csm->awd = awd;
	csm->dma = dma;
	csm->dmaChannel = dmaChannel;
	csm->transceiver = transceiver;
	csm->state = OSCI_CHANNEL_STATE_SHUTDOWN;
	csm->events.measurement_complete = FALSE;
	csm->events.shutdown = FALSE;
	csm->events.start_measuring = FALSE;
	csm->events.start_monitoring = FALSE;
	csm->channelOpcode = channelOpcode;

	// Initialize static callbacks.
	OSCI_dma_set_TC_callback(csm, measurement_complete_callback);
	OSCI_adc_set_awd_callback(csm, awd_threshold_callback);
	OSCI_timer_set_update_callback(csm->holdOffTimer, holdOffTimerCallback);

	// Initialize nested structures.
	OSCI_dma_channel_init(csm);
	OSCI_adc_init(csm);

}

void OSCI_channel_start_measuring(Osci_ChannelStateMachine* csm)
{
	OSCI_adc_stop(csm);
	OSCI_timer_stop(csm->timer);
	LL_DMA_DisableChannel(csm->dma, csm->dmaChannel);

	OSCI_timer_setup(csm->timer, csm->params.timerSettings);

	OSCI_adc_reconfigure_for_measuring(csm);
	OSCI_dma_channel_reconfigure_for_measuring(csm);

	csm->state = OSCI_CHANNEL_STATE_MEASURING;

	OSCI_timer_start(csm->timer);
	LL_ADC_REG_StartConversion(csm->adc);
}

void OSCI_channel_start_monitoring(Osci_ChannelStateMachine* csm)
{
	if (!csm->params.triggerLevel)
	{
		OSCI_channel_start_measuring(csm);
		//csm->events.start_measuring = TRUE;
		return;
	}

	OSCI_adc_stop(csm);
	OSCI_timer_stop(csm->timer);
	LL_DMA_DisableChannel(csm->dma, csm->dmaChannel);

	OSCI_adc_reconfigure_for_monitoring(csm);

	csm->state = OSCI_CHANNEL_STATE_MONITORING;

	LL_ADC_REG_StartConversion(csm->adc);
}



void OSCI_channel_update(Osci_ChannelStateMachine* csm)
{
	switch(csm->state)
	{
		case OSCI_CHANNEL_STATE_SHUTDOWN:
		{
			// Clear invalid event flags
			csm->events.measurement_complete = FALSE;
			csm->events.shutdown = FALSE;

			// Check for transitions
			if (csm->events.start_monitoring)
			{
				OSCI_channel_start_monitoring(csm);
				csm->events.start_monitoring = FALSE;
			}

			/*if(csm->events.start_measuring)
			{
				OSCI_channel_start_measuring(csm);
				csm->events.start_measuring = FALSE;
				return;
			}*/
			break;
		}
		case OSCI_CHANNEL_STATE_MONITORING:
		{
			// Clear invalid event flags
			csm->events.measurement_complete = FALSE;
			csm->events.start_monitoring = FALSE;

			// Check for transitions
			if (csm->events.shutdown)
			{
				OSCI_adc_stop(csm);
				OSCI_timer_stop(csm->holdOffTimer);
				csm->state = OSCI_CHANNEL_STATE_SHUTDOWN;
				csm->events.shutdown = FALSE;
				return;
			}

			/*if (csm->events.start_measuring)
			{
				OSCI_channel_start_measuring(csm);
				csm->events.start_measuring = FALSE;
				return;
			}*/
			break;
		}
		case OSCI_CHANNEL_STATE_MEASURING:
		{
			// Clear invalid event flags
			csm->events.start_measuring = FALSE;
			csm->events.start_monitoring = FALSE;

			// Check for transitions
			if(csm->events.shutdown)
			{
				OSCI_adc_stop(csm);
				OSCI_timer_stop(csm->holdOffTimer);
				csm->state = OSCI_CHANNEL_STATE_SHUTDOWN;
				return;
			}

			if(csm->events.measurement_complete)
			{
				csm->events.measurement_complete = FALSE;

				OSCI_adc_stop(csm);
				csm->state = OSCI_CHANNEL_STATE_SHUTDOWN;

				if (csm == csm->transceiver->x_channel_state_machine)
				{
					csm->transceiver->events.send_requested[0] = TRUE;

					if ((csm->transceiver->channelUpdateMask & MEASURE_CONTINUOUS_X)
							&& !(OSCI_is_channel_holdoff_timer_active(csm->transceiver, CHANNEL_X)))
						csm->events.start_monitoring = TRUE;
				}
				else
				{
					csm->transceiver->events.send_requested[1] = TRUE;

					if ((csm->transceiver->channelUpdateMask & MEASURE_CONTINUOUS_Y)
							&& !(OSCI_is_channel_holdoff_timer_active(csm->transceiver, CHANNEL_Y)))
						csm->events.start_monitoring = TRUE;
				}
			}
			break;
		}
	}
}

void OSCI_channel_measurement_complete_callback_x(Osci_Application* app)
{
	// Only applies in measuring state
	if (app->xChannelStateMachine.state != OSCI_CHANNEL_STATE_MEASURING)
		return;

	OSCI_timer_stop(app->xChannelStateMachine.timer);

	app->xChannelStateMachine.measurement = app->xChannelStateMachine.measurementDMABuffer;
	app->xChannelStateMachine.events.measurement_complete = TRUE;
}

void OSCI_channel_measurement_complete_callback_y(Osci_Application* app)
{
	// Only applies in measuring state
	if (app->yChannelStateMachine.state != OSCI_CHANNEL_STATE_MEASURING)
		return;

	OSCI_timer_stop(app->yChannelStateMachine.timer);

	app->yChannelStateMachine.measurement = app->yChannelStateMachine.measurementDMABuffer;
	app->yChannelStateMachine.events.measurement_complete = TRUE;
}

void OSCI_channel_awd_threshold_callback_x(Osci_Application* app)
{
	LL_ADC_DisableIT_AWD1(app->xChannelStateMachine.adc);

	if (app->xChannelStateMachine.state != OSCI_CHANNEL_STATE_MONITORING)
		return;

	//app->xChannelStateMachine.events.start_measuring = TRUE;
	OSCI_channel_start_measuring(&app->xChannelStateMachine);
}

void OSCI_channel_awd_threshold_callback_y(Osci_Application* app)
{
	LL_ADC_DisableIT_AWD2(app->yChannelStateMachine.adc);

	if (app->yChannelStateMachine.state != OSCI_CHANNEL_STATE_MONITORING)
		return;

	//app->yChannelStateMachine.events.start_measuring = TRUE;
	OSCI_channel_start_measuring(&app->yChannelStateMachine);
}

void OSCI_channel_hold_off_callback_x(Osci_Application* app)
{
	if (app->xChannelStateMachine.state != OSCI_CHANNEL_STATE_SHUTDOWN || app->transceiver.state != OSCI_TRANSCEIVER_STATE_IDLE)
		return;

	app->xChannelStateMachine.events.start_monitoring = TRUE;
}

void OSCI_channel_hold_off_callback_y(Osci_Application* app)
{
	if (app->yChannelStateMachine.state != OSCI_CHANNEL_STATE_SHUTDOWN || app->transceiver.state != OSCI_TRANSCEIVER_STATE_IDLE)
		return;

	app->yChannelStateMachine.events.start_monitoring = TRUE;
}
