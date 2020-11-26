/*
 * LED.c
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#include "Lamp.h"

void Lamp_init(void)
{
	PORT_setPinDirection(LAMP_PORT,LAMP_PIN,PORT_PIN_OUT);
	Dio_writePinValue(LAMP_PORT,LAMP_PIN,STD_LOW);
}

void Lamp_on(void)
{
	Dio_writePinValue(LAMP_PORT,LAMP_PIN,STD_HIGH);
}
void Lamp_off(void)
{
	Dio_writePinValue(LAMP_PORT,LAMP_PIN,STD_LOW);
}

uint8 Lamp_state(void)
{
	uint8 state = Dio_readPinValue(LAMP_PORT, LAMP_PIN);
	return state;

}

