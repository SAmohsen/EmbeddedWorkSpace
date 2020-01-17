/*
 * clock.h
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "LCD.h"
#include "date.h"
#include "alarm.h"


#define MAX_SECONDS_PER_MINUTE 60
#define MAX_MINUTES_PER_HOUR 60
#define MAX_HOURS_PER_DAY 24



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/*
 * Variables To Hold Clock time in 24 Mode
 */
extern uint8 g_seconds ;
extern uint8 g_minutes ;
extern uint8 g_12hours ;
extern uint8 g_24hours ;
extern uint8 g_periodFlag ;


/**************************************************************************************
 * 							Function ProtoTypes										  *
 * ************************************************************************************/


/*
 * Function Called Every second To Increment Base Unit Of  Time
 */
void tick();
/*
 *Function To Update Clock
 */
void updatetime();
/*
 * Function To Display Clock On LCD
 */

void displaytime() ;

#endif /* CLOCK_H_ */
