/*
 * alarm.h
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "DIO.h"
#include "date.h"
#include "clock.h"
#include "GPT.h"

#define ALARM_NOT_SET 0
#define ALARM_SET 1

#define MAX_DELAY_TIME 36

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern volatile uint8 g_Alarmseconds ;
extern volatile uint8 g_Alarmminutes ;
extern volatile uint8 g_Alarmhours  ;
extern volatile uint8 g_AlarmperiodFlag ;
extern volatile uint8 g_Alarmstatus ;
extern volatile uint8 delay;

/**************************************************************************************
 * 							Function ProtoTypes										  *
 * ************************************************************************************/

void incrementAlarmSeconds();
/*
 * Function To Increment Alarm Minutes
 */
void incrementAlarmMinutes();
/*
 * Function To Increment Alarm Hours
 */
void incrementAlarmHours();

void alarmRuntime();
/*
 * Function To Fire Alarm
 */
void fire_alarm();
/*
 * Function To Disable Alarm
 */
void disable_alarm();
/*
 * Function To Check Alarm
 */
void checkalarm();
/*
 * Function Called To Set Alarm
 */
void setAlarm(uint8 hours, uint8 minutes, uint8 seconds, uint8 period);
/*
 * Function To Display Alarm
 */
void displayalarm() ;

#endif /* ALARM_H_ */
