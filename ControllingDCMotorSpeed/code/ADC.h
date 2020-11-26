/*
 * ADC.h
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "std_types.h"
#include "common_marcos.h"
#include  "micro_config.h"



#define ADC_INITIALIZED                (1U)
#define ADC_NOT_INITIALIZED            (0U)
#define NUMBER_ADC_CHANNELS (7U)

/*************************************************************************************
 	 	 	 	 	 	 	 	 Module DataTypes
 **************************************************************** ********************/
typedef uint16 Adc_ValueGroupType ; //type to hold ADC result

typedef enum {
	ADC_IDLE,
	ADC_BUSY,
	ADC_COMPLETED,
	ADC_STREAM_COMPLETED
}Adc_StatusType;


typedef enum {
	ADC_ALIGN_LEFT,
	ADC_ALIGN_RIGHT
}Adc_ResultAlignmentType;

typedef enum {
	Adc_channel0,
	Adc_channel1,
	Adc_channel2,
	Adc_channel3,
	Adc_channel4,
	Adc_channel5,
	Adc_channel6,
	Adc_channel7,
}Adc_Channel;

typedef enum {
	Aref ,
	AVCC,
	internal
}Adc_RefernceVoltage;

typedef enum {
	Prescale_2 =1,
	Prescale_4,
	Prescale_8,
	Prescale_16,
	Prescale_32,
	Prescale_64,
	Prescale_128
}Adc_PrescaleType;

typedef struct {
	Adc_RefernceVoltage refrence_volt ;
	Adc_PrescaleType prescale ;
	Adc_ResultAlignmentType aligment ;
}Adc_ConfigChannel;

/**************************************************************************************
 * 							Function ProtoTypes
 * ************************************************************************************/

void Adc_Init(const Adc_ConfigChannel * Config_Ptr);
void Adc_DeInit();
Adc_ValueGroupType Adc_StartConversion(Adc_Channel channel) ;

#endif /* ADC_ADC_H_ */
