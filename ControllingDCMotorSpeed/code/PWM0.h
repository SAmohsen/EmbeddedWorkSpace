/*
 * PWM0.h
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */

#ifndef PWM0_H_
#define PWM0_H_


#include"main.h"
void PWM_Timer0_Init(unsigned char set_duty_cycle);
void PWM_setOCR0(uint8 duty);
#endif /* PWM0_H_ */
