 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Adc Module.
 *
 * Author: sayed mohsen
 ******************************************************************************/

#include "ADC.h"

const Adc_ConfigType Adc_configuration ={Aref,Adc_Prescale_8,ADC_ALIGN_RIGHT,Adc_polling};
