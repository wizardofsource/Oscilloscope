/*
 * osci_transform.c
 *
 *  Created on: 3. 12. 2019
 *      Author: dot
 */

#include"osci_transform.h"

void OSCI_transform_apply(Osci_DataFrame* df, Osci_ChannelParameters params)
{
	// Apply the transformation to each datapoint.
	// v =  1/sensitivity * v * calib + offset
	// and then make sure v is in range <0, 4095> by min, max
	for(uint32_t i = 0; i < NUM_SAMPLES;i++)
		df->channelData.values[i] = MIN(MAX(floor(1/params.sensitivity*df->channelData.values[i]*params.alpha + params.offset), DATA_MIN_VALUE), DATA_MAX_VALUE);
}

