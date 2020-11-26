 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/


#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"




/*
 * Macros for ADC Status
 */
#define ADC_INITIALIZED                (1U)
#define ADC_NOT_INITIALIZED            (0U)

/*number of ADC channels */
#define NUMBER_ADC_CHANNELS (7U)

/*ADC Auto Triggering Mode*/
#define ADC_AUTO_TRIGGERING_MODE (STD_ON)
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef uint16 Adc_ValueGroupType ; /*type to hold ADC result*/

typedef enum{
	Adc_polling,
	Adc_interrupts
}Adc_ResultReadMode;/*type for method reading ADC Value*/
typedef enum {
	ADC_ALIGN_LEFT,
	ADC_ALIGN_RIGHT
}Adc_ResultAlignmentType;/*type For ADC Result Alignment*/

typedef enum {
	Adc_channel0,
	Adc_channel1,
	Adc_channel2,
	Adc_channel3,
	Adc_channel4,
	Adc_channel5,
	Adc_channel6,
	Adc_channel7,
}Adc_Channel;/*type for ADC Channels */

typedef enum {
	Aref ,
	AVCC,
	internal=3
}Adc_RefernceVoltage;/*Type For ADC Reference Voltage */

typedef enum {
	Adc_Prescale_2 =1,
	Adc_Prescale_4,
	Adc_Prescale_8,
	Adc_Prescale_16,
	Adc_Prescale_32,
	Adc_Prescale_64,
	Adc_Prescale_128
}Adc_PrescaleType;/*type For ADC Clock*/

typedef enum{
Adc_AutoTriggeringDisable,
Adc_AutoTrigger_FREE_RUNNING_MOD=0,
Adc_AutoTrigger_ANALOG_COMPARTOR,
Adc_AutoTrigger_EXT_INT0,
Adc_AutoTrigger_TIMER0_CMPMATCH,
Adc_AutoTrigger_TIMER0_OVF,
Adc_AutoTrigger_TIMER1_CMPMATCH_B,
Adc_AutoTrigger_TIMER1_OVF,
Adc_AutoTrigger_TIMER1_ICU
}Adc_TriggeringMode;/*Type For ADC Triggering Mode*/

typedef struct {
	Adc_RefernceVoltage refrence_volt ;
	Adc_PrescaleType prescale ;
	Adc_ResultAlignmentType aligment ;
	Adc_ResultReadMode mode ;
	Adc_TriggeringMode triggeringmode ;
}Adc_ConfigType;/*Type For ADC Configuration*/

/**************************************************************************************
 * 							Function ProtoTypes
 * ************************************************************************************/

void Adc_init(const Adc_ConfigType *Config_Ptr) ;
Adc_ValueGroupType Adc_readChannel(Adc_Channel channel) ;
void Adc_enableInterrupt(void);
void Adc_disableInterrupt(void);
Adc_ValueGroupType Adc_getAdcResult(void);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Adc_ConfigType Adc_configuration;

#endif /* ADC_ADC_H_ */
