/*
 * DC_Motor.c
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */


#include "DCMotor.h"

void DCMotor_Init(){
	SET_BIT(DCMOTOR_DDR,DCMOTOR_INPUT1);
	SET_BIT(DCMOTOR_DDR,DCMOTOR_INPUT2);
}


void DCMotor_RotateClockwise(){
	CLR_BIT(DCMOTOR_PORT,DCMOTOR_INPUT1);
	SET_BIT(DCMOTOR_PORT,DCMOTOR_INPUT2);
}
void DCMotor_RotateAntiClockwise(){
	SET_BIT(DCMOTOR_PORT,DCMOTOR_INPUT1);
	CLR_BIT(DCMOTOR_PORT,DCMOTOR_INPUT2);
}
void DCMotor_Stop(){
CLR_BIT(DCMOTOR_PORT,DCMOTOR_INPUT1);
CLR_BIT(DCMOTOR_PORT,DCMOTOR_INPUT2);
}
