/*
 * ADC.c
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */


#include "ADC.h"

static uint8 Adc_Status = ADC_NOT_INITIALIZED ;
static Adc_ConfigChannel *Adc_ConfiguredChannels = NULL_PTR ;

void Adc_Init(const Adc_ConfigChannel * Config_Ptr){
	boolean error = FALSE ;
	if (NULL_PTR == Config_Ptr)
	{
		error = TRUE ;

	}

	else
	{
		/*NO Action Required */
	}

	if (FALSE == error)
	{
		Adc_ConfiguredChannels = Config_Ptr ;

		/* ADC Enable */
		SET_BIT(ADCSRA,ADEN);

		switch (Adc_ConfiguredChannels->refrence_volt)
		{
		case Aref: CLR_BIT(ADMUX,REFS0) ;
				   CLR_BIT(ADMUX,REFS1) ;

		break ;

		case AVCC: CLR_BIT(ADMUX,REFS0) ;
				   SET_BIT(ADMUX,REFS1) ;
		break ;

		case internal:SET_BIT(ADMUX,REFS0) ;
		   	   	   	  SET_BIT(ADMUX,REFS1) ;
		break ;
		}

		switch (Adc_ConfiguredChannels->aligment)
		{
		case ADC_ALIGN_LEFT:SET_BIT(ADMUX,ADLAR) ;

		break ;
		case ADC_ALIGN_RIGHT:CLR_BIT(ADMUX,ADLAR) ;
		break ;
		}
		/*bit masking Always A better option :"D */

		switch (Adc_ConfiguredChannels->prescale)
		{
		case Prescale_2 :SET_BIT(ADCSRA,ADPS0);
						 CLR_BIT(ADCSRA,ADPS1);
						 CLR_BIT(ADCSRA,ADPS2);
		break ;

		case Prescale_4:CLR_BIT(ADCSRA,ADPS0);
						SET_BIT(ADCSRA,ADPS1);
						CLR_BIT(ADCSRA,ADPS2);
		break ;

		case Prescale_8: SET_BIT(ADCSRA,ADPS0);
						 SET_BIT(ADCSRA,ADPS1);
						 CLR_BIT(ADCSRA,ADPS2);
		break;

		case Prescale_16:CLR_BIT(ADCSRA,ADPS0);
						CLR_BIT(ADCSRA,ADPS0);
						SET_BIT(ADCSRA,ADPS2);

		break ;


		case Prescale_32:SET_BIT(ADCSRA,ADPS0);
						 CLR_BIT(ADCSRA,ADPS1);
						 SET_BIT(ADCSRA,ADPS2);
		break ;

		case Prescale_64:CLR_BIT(ADCSRA,ADPS0);
						 SET_BIT(ADCSRA,ADPS1);
						 SET_BIT(ADCSRA,ADPS2);
		break ;

		case Prescale_128: SET_BIT(ADCSRA,ADPS0);
						   SET_BIT(ADCSRA,ADPS1);
						   SET_BIT(ADCSRA,ADPS2);
		break ;
		}
		Adc_Status = ADC_INITIALIZED ;
	}
	else
	{
		/*NO Action Required */
	}

}


void Adc_DeInit(){
	Adc_ConfiguredChannels = NULL_PTR ;
}

Adc_ValueGroupType Adc_StartConversion(Adc_Channel channel){
	boolean error = FALSE ;
	if (ADC_NOT_INITIALIZED ==Adc_Status)
	{
		/* report ADC  not initialized Error*/
		error = TRUE ;
	}
	else
	{

	}
	if (NUMBER_ADC_CHANNELS <= channel)
	{
		/*Error parameters*/
		error  = TRUE ;
	}
	else
	{

	}

	if (FALSE == error)
	{
		SET_BIT(ADCSRA,ADSC);
		ADMUX = (ADMUX & 0xE0 ) | (channel & 0x07);
		while(BIT_IS_CLEAR(ADCSRA,ADIF));//wait until Adc Finish Conversion
		SET_BIT(ADCSRA,ADIF);//Clear Flag by writing 1 in it
		return  ADC ;
	}
	else
	{

	}
}
