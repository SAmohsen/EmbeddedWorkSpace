/*
 * GPT.h
 *
 *  Created on: Nov 10, 2019
 *      Author: sayed
 */

#ifndef GPT_GPT_H_
#define GPT_GPT_H_

#include "std_types.h"
#include "common_marcos.h"
#include  "micro_config.h"


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
void Gpt0_init(Gpt_ConfigChannel *Config_ptr);
void Gpt2_init(Gpt_ConfigChannel *Config_ptr);
void Gpt0_SetOcrValue(uint8 ocr_value);
void Gpt2_SetOcrValue(uint8 ocr_value);
void Gpt0_OvfInterruptEnable();
void Gpt2_OvfInterruptEnable();
void Gpt0_OcrInterruptEnable();
void Gpt2_OcrInterruptEnable();
void Gpt2_deinit();
void Gpt2_OcrInterruptDisable();

void Gpt0_OvfSetCallback(void (*a_ptr)(void));
void Gpt2_OvfSetCallback(void (*a_ptr)(void));
void Gpt0_OcrSetCallback(void (*a_ptr)(void));
void Gpt2_OcrSetCallback(void (*a_ptr)(void));
void Timer1_InitoneSecond();
void Gpt1_OcrSetCallback(void (*a_ptr)(void));

extern Gpt_ConfigChannel Gpt0_configuration ;
extern Gpt_ConfigChannel Gpt2_configuration;
#endif /* GPT_GPT_H_ */
