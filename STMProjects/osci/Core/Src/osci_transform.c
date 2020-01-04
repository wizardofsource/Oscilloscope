/*
 * osci_transform.c
 *
 *  Created on: 3. 12. 2019
 *      Author: dot
 */

#include"osci_transform.h"

void OSCI_transform_apply(Osci_DataFrame* df, Osci_ChannelParameters params)
{
	for(uint32_t i = 0; i < NUM_SAMPLES;i++)
		df->channelData.values[i] = MIN(MAX(floor(1/params.sensitivity*df->channelData.values[i]*params.alpha + params.offset), DATA_MIN_VALUE), DATA_MAX_VALUE);
}

