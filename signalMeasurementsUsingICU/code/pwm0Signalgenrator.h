/*
 * pwm0Signalgenrator.h
 *
 *  Created on: Jan 5, 2020
 *      Author: sayed
 */

#ifndef PWM0SIGNALGENRATOR_H_
#define PWM0SIGNALGENRATOR_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_marcos.h"
#include "LCD.h"
void PWM_Timer0_Init() ;
void PWM_setOCR0(uint8 duty) ;
uint16 adjustprescalvalue(uint16 N) ;
void settimer0prescaleValue(uint16 N) ;
void displaygenratedsignal();
void genratepwmSignal(uint8 dutycycle, uint16 freq) ;

#endif /* PWM0SIGNALGENRATOR_H_ */
