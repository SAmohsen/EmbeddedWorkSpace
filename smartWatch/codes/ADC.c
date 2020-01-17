 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for  ADC driver
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/


#include "ADC.h"

static uint8 Adc_Status = ADC_NOT_INITIALIZED ;/*static global variable for ADC status */
static const Adc_ConfigType *Adc_configureChannels = NULL_PTR;/*static global variable for ADC Configurations*/
static volatile uint16 g_adcResult = 0 ;/*global variable to hold ADC Result*/



/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/
ISR(ADC_vect) {
	g_adcResult = ADC;/*Read ADC after conversion complete */
}/*flag cleared automatically after executing ISR*/



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void Adc_init(const Adc_ConfigType *Config_Ptr) {
	if (NULL_PTR != Config_Ptr) {
		Adc_configureChannels = Config_Ptr;
		SET_BIT(ADCSRA, ADEN);/*Enable ADC*/
		ADMUX  = (ADMUX & 0x3F)  | ((Adc_configureChannels->refrence_volt & 0x03) << 6);/*set ADC reference volt */
		ADCSRA = (ADCSRA & 0xF8) | (Adc_configureChannels->prescale & 0x07);/*set ADC prescale value ADC must operate in range 50-200Khz*/
		switch (Adc_configureChannels->aligment)/*ADC result Alignment*/
		{
		case ADC_ALIGN_LEFT:SET_BIT(ADMUX,ADLAR);
		break;
		case ADC_ALIGN_RIGHT:CLR_BIT(ADMUX,ADLAR);
		break;
		}
		if (Adc_interrupts == Adc_configureChannels->mode) {
			SET_BIT(ADCSRA, ADIE);/*enable ADC interrupts*/
		}
		if ( ADC_AUTO_TRIGGERING_MODE == STD_ON) {
			SET_BIT(ADCSRA, ADATE);/*Enable ADC auto triggering mode */
			SFIOR = (Adc_configureChannels->triggeringmode << 5);/*set ADC Triggering Mode*/
		}

		Adc_Status = ADC_INITIALIZED;
	}
}


Adc_ValueGroupType Adc_readChannel(Adc_Channel channel) {
	Adc_ValueGroupType Adc_result = 0;
	if (ADC_INITIALIZED == Adc_Status) {
		ADMUX = (ADMUX & 0xE0) | (channel & 0x07);/*set correct channel*/
		if (STD_OFF == ADC_AUTO_TRIGGERING_MODE)
		{
			if (Adc_interrupts == Adc_configureChannels->mode)
			{
				SET_BIT(ADCSRA, ADSC);/*start conversion*/
			}
			else if (Adc_polling == Adc_configureChannels->mode)
			{
				SET_BIT(ADCSRA, ADSC);/*start conversion*/
				while (BIT_IS_CLEAR(ADCSRA, ADIF)); /*wait until ADC Finish Conversion*/
				SET_BIT(ADCSRA, ADIF); /* Clear Flag by writing 1 in it*/
				Adc_result = ADC;/*read ADC Value*/
			}
			else
			{
				/*no Action Required*/
			}

		}
	}

	return Adc_result;
}

void Adc_enableInterrupt(void) {
	SET_BIT(ADCSRA, ADIE);/*enable ADC interrupts*/
}
void Adc_disableInterrupt(void) {
	CLR_BIT(ADCSRA, ADIE);/*disable ADC interrupts*/
}

Adc_ValueGroupType Adc_getAdcResult(void){
	return g_adcResult;
}

