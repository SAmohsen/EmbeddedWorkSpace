/*
 * date.h
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#ifndef DATE_H_
#define DATE_H_

#include "LCD.h"
#include "clock.h"


#define MAX_DAYS_PER_MONTHS 30
#define MAX_MONTHS_PER_YEAR 12


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern uint8 g_days ;
extern uint8 g_months ;
extern uint8 g_years ;


/**************************************************************************************
 * 							Function ProtoTypes										  *
 * ************************************************************************************/

/*
 *Function To Update Date
 */
void updatedate();

/*
 * Function To Display Date On LCD
 */
void displaydate();

#endif /* DATE_H_ */
