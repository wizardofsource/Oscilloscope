/*
 * SignalAdjuster.cpp
 *
 *  Created on: Dec 27, 2019
 *      Author: dot
 */

#include "SignalAdjuster.h"

void c_putSignalToDAC(void *v) {
	SignalAdjuster *p = (SignalAdjuster*) v;
	LL_DAC_ConvertData12RightAligned(DAC1, LL_DAC_CHANNEL_1, p->getNextSample());
}

void SignalAdjuster::sample() {
	float signal_increment = 2 * M_PI / (NUM_SAMPLES - 1);
	sampleIndex = 0;
	for (uint32_t i = 0; i < NUM_SAMPLES; i++) {
		signalBuffer[i] = MIN(MAX((offset + amplitude*sin(signal_increment * i))/3.3*4095, 0), 4095);
	}

	configureTimer();
}

void SignalAdjuster::configureTimer() {
	LL_TIM_DisableCounter(TIM1);
	LL_TIM_ClearFlag_UPDATE(TIM1);
	LL_TIM_SetCounter(TIM1, 0);

	// Asumes TIM1 is used with 8MHZ clock speed
	float cyclesPerSample = TIM1_CLOCK_SPEED / frequency / (NUM_SAMPLES - 1);
	uint16_t overflows = floor(cyclesPerSample/65535);
	TIM1->PSC = overflows;
	TIM1->ARR = cyclesPerSample/(overflows + 1)-1;

	LL_TIM_EnableIT_UPDATE(TIM1);
	LL_TIM_EnableCounter(TIM1);
}

uint32_t SignalAdjuster::getNextSample() {
	uint32_t ret = signalBuffer[sampleIndex];
	++sampleIndex;
	sampleIndex %= NUM_SAMPLES;
	return ret;
}

void SignalAdjuster::start(){
	sample();
}
