/*
 * DC_Motor.c
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */


#include "DCMotor.h"

void DCMotor_Init()
{
	PORT_setPinDirection(DCMOTOR_PORT,DCMOTOR_INPUT1,PORT_PIN_OUT);
	PORT_setPinDirection(DCMOTOR_PORT,DCMOTOR_INPUT2,PORT_PIN_OUT);
}


void DCMotor_RotateClockwise()
{
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT1,STD_LOW);
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT2,STD_HIGH);
}
void DCMotor_RotateAntiClockwise()
{
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT1,STD_HIGH);
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT2,STD_LOW);
}
void DCMotor_Stop()
{
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT1,STD_LOW);
	Dio_writePinValue(DCMOTOR_PORT,DCMOTOR_INPUT2,STD_LOW);
}
