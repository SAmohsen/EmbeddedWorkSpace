/*
 * Button.c
 *
 *  Created on: Feb 17, 2020
 *      Author: SAmohsen
 */

#include "Button.h"
/*Pull UP*/

static uint8 PULL_UP_BUTTON=BUTTON_IS_REALSED ;

void BUTTON_init()
{
	PORT_setPinDirection(BUTTON_PORT,BUTTON_PIN,PORT_PIN_IN);
}

void BUTTON_refreshState() {
	if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW)
	{
		_delay_ms(60);
		if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW)
		{
			PULL_UP_BUTTON = BUTTON_IS_PRESSED;
		}
	}
	else
	{
		PULL_UP_BUTTON = BUTTON_IS_REALSED;
	}
}

uint8 BUTTON_getState()
{
	return PULL_UP_BUTTON ;
}

uint8 BUTTON_ReadState()
{
	if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW)
		{
			_delay_ms(60);
			if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW)
			{
				PULL_UP_BUTTON = BUTTON_IS_PRESSED;
			}
		}
		else
		{
			PULL_UP_BUTTON = BUTTON_IS_REALSED;
		}
	return PULL_UP_BUTTON;
}
