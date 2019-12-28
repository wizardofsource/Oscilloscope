/*
 * osci_transform.c
 *
 *  Created on: 3. 12. 2019
 *      Author: dot
 */

#include"osci_transform.h"
/*
void osci_transform_with_copied_settings(void (*transform_fcn) (Osci_DataFrame*, Osci_Settings, Osci_CalculatedParameters), Osci_DataFrame* data){
	// Copy current settings, make sure they do not change while this data frame is transformed, mparams do not need to be copied but, just in case
	transform_fcn(data, osci_settings_recvCompleteBuffer, osci_calculatedparameters);
}

void osci_transform_sensitvity_and_offset_transform_in_range(Osci_DataFrame* frame, Osci_Settings settings, Osci_CalculatedParameters mparams){

	for(uint32_t i = 0; i < NUM_SAMPLES;i++){
		frame->yChannel.values[i] = MIN(MAX(floor(mparams.sensitivity_conversion_y*frame->yChannel.values[i] + mparams.offset_conversion_y*settings.yOffset), DATA_MIN_VALUE), DATA_MAX_VALUE);
		frame->xChannel.values[i] = MIN(MAX(floor(mparams.sensitivity_conversion_x*frame->xChannel.values[i] + mparams.offset_conversion_x*settings.xOffset), DATA_MIN_VALUE), DATA_MAX_VALUE);
	}
}*/

void OSCI_transform_apply(Osci_DataFrame* df, Osci_ChannelParameters px, Osci_ChannelParameters py)
{
	for(uint32_t i = 0; i < NUM_SAMPLES;i++)
	{
		df->xChannel.values[i] = MIN(MAX(floor(px.sensitivity*df->xChannel.values[i] + px.offset), DATA_MIN_VALUE), DATA_MAX_VALUE);
		df->yChannel.values[i] = MIN(MAX(floor(py.sensitivity*df->yChannel.values[i] + py.offset), DATA_MIN_VALUE), DATA_MAX_VALUE);
	}
}

/*
void osci_transform_apply_transform(){

}

void osci_transform_apply_transforms(){
	// Copy last complete measurement
	osci_dataframe_transformed = osci_dataframe_recvCompleteBuffer;
	// and transform
	osci_transform_with_copied_settings(osci_transform_sensitvity_and_offset_transform_in_range, &osci_dataframe_transformed);
}
*/




