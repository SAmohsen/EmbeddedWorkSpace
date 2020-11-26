/*
 * GPT.h
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */

#ifndef GPT_GPT_H_
#define GPT_GPT_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"


/*************************************************************************************
 	 	 	 	 	 	 	 	 Module DataTypes
 **************************************************************** ********************/


typedef enum{
	timer_mode_Normal,
	timer_mode_CTC,
}Gpt_WaveformGenerationType;


typedef enum {
	OC0_disconnected,
	toggle_OC0_on_Compare_match,
	clear_OC0_on_Compare_match,
	set_OC0_on_Compare_Match
}Gpt_CompareOutputModeType;


typedef enum {
	no_prescale,
	Gpt_Prescale_8,
	Gpt_Prescale_64,
	Gpt_Prescale_256,
	Gpt_Prescale_1024,
}Gpt_PrescaleType;


typedef struct {
	Gpt_WaveformGenerationType mode ;
	Gpt_CompareOutputModeType OCR_mode;
	Gpt_PrescaleType prescale ;
}Gpt_ConfigChannel;

/********************************************************************
 * 						Function ProtoTypes
 * ******************************************************************/
void Timer1_InitoneSecond() ;
void Gpt1_OcrSetCallback(void (*a_ptr)(void));
void Timer1_deInit();
#endif /* GPT_GPT_H_ */
