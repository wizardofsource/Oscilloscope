/*
 * osci_timers.c
 *
 *  Created on: Dec 23, 2019
 *      Author: dot
 */

#include <osci_timer.h>
#include "main.h"

void OSCI_timer_stop(TIM_TypeDef* timer)
{
	LL_TIM_DisableCounter(timer);
}

void OSCI_timer_start(TIM_TypeDef* timer)
{
	LL_TIM_EnableUpdateEvent(timer);
	LL_TIM_EnableIT_UPDATE(timer);

	LL_TIM_SetCounter(timer, 0);
	LL_TIM_EnableCounter(timer);
}

void OSCI_timer_set_update_callback(TIM_TypeDef* timer, ADC_callback new_callback)
{
	if (timer == TIM3)
		osci_timer3_update_callback = new_callback;
	else if (timer == TIM15)
		osci_timer15_update_callback = new_callback;
}

void OSCI_timer_setup(TIM_TypeDef* timer, Osci_TimerSettings settings)
{
	timer->PSC = settings.psc;
	timer->ARR = settings.arr;
}

