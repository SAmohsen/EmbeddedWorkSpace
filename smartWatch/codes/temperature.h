/*
 * temperature.h
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "LCD.h"
#include "LM35.h"





/**************************************************************************************
 * 							Function ProtoTypes										  *
 * ************************************************************************************/

/*
 * Function To Update Temperature
 */
void updatetemp();

/*
 * Function To Display Temperature On LCD
 */
void displaytemp();

#endif /* TEMPERATURE_H_ */
