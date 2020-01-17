/*
 * SmartWatch.h
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#ifndef SMARTWATCH_H_
#define SMARTWATCH_H_

#include "common_marcos.h"
#include "micro_config.h"
#include "std_types.h"
#include "main.h"
#include "port_PBcfg.h"
#include "DIO_PBcfg.h"
#include "ADC.h"
#include "Interrupts_PBcfg.h"
#include "date.h"
#include "clock.h"
#include "temperature.h"
#include "alarm.h"
#include "GPT.h"


/**************************************************************************************
 * 							Function ProtoTypes										  *
 * ************************************************************************************/

/* Task Called Once to initialize all smartWatch Modules */
void smartWatch_initTask(void) ;
/* Task Called Every 20 MS To update Clock */
void Clock_Task(void);
/* Task Called Every 100 MS To Update Date */
void Date_Task(void);
/* Task Called Every 60 MS To Update Temperature */
void Temperature_Task(void);
/* Task Called Every  40 MS To Check Alarm */
void Alarm_Task(void);
/*Task Called Once To init LCD Display*/
void Display_Task(void);
#endif /* SMARTWATCH_H_ */
