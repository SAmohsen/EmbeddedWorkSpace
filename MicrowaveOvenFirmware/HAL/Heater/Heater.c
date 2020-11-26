/*
 * LED.c
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#include "Heater.h"


void Heater_init(void)
{
		PORT_setPinDirection(HEATER_PORT,HEATER_PIN,PORT_PIN_OUT);
		Dio_writePinValue(HEATER_PORT,HEATER_PIN,STD_LOW);
}

void Heater_on(void)
{
	Dio_writePinValue(HEATER_PORT,HEATER_PIN,STD_HIGH);

}

void Heater_off(void)
{
	Dio_writePinValue(HEATER_PORT,HEATER_PIN,STD_LOW);
}

uint8 Heater_State(void)
{
	uint8 state = Dio_readPinValue(HEATER_PORT, HEATER_PIN);
	return state ;

}


