/*
 * door.c
 *
 *  Created on: Jan 10, 2020
 *      Author: sayed
 */

#include "door.h"

static char key;
static char *pass;
static uint8 status;
uint8 DoorStatus = DOOR_IS_LOCKED;
uint8 volatile tick = 0;


void increament_tick() {
	tick++;
}

static void displaydoorstatus()
{
	LCD_goToXY(1, 1);
	LCD_SendString("The Door Is ");
	LCD_goToXY(2, 5);
	if (DOOR_IS_LOCKED == DoorStatus)
	{
		LCD_SendString("locked ! ");
		LCD_goToXY(3, 1);
		LCD_SendString("- :open Door");
	}
	else if (DOOR_IS_OPENED == DoorStatus)
	{
		LCD_SendString("opened ! ");
		LCD_goToXY(3, 1);
		LCD_SendString("- :close Door");
	}
	else
	{
		/*no Action Required */
	}

	LCD_goToXY(4, 1);
	LCD_SendString("+ :change Pass");
}

void doorsetup() {
	LCD_Init();
	Uart_init(&UartConfigurations);
	DDRB |= 0xF0;
	PORTB &= 0x0F;
	timer1_setCallback(increament_tick);
	sei();
}



void doorLoop() {
	displaydoorstatus();
	if (DOOR_IS_LOCKED == DoorStatus)
	{
		Uart_SendU8Data('L');
	}
	else if (DOOR_IS_OPENED == DoorStatus)
	{
		Uart_SendU8Data('O');
	}
	else
	{
		/*no Action Required */
	}

	key = Keypad_getPressedKey();

	if ((key == '-') && (DoorStatus == DOOR_IS_OPENED))
	{
		DoorStatus = DOOR_IS_LOCKED;

	}
	else if ((key == '+') || (key == '-'))
	{
		LCD_Clear();
		LCD_goToXY(1, 2);
		LCD_SendString("Enter Pass");
		LCD_goToXY(2, 1);
		pass = takePassword();
		status = checkpasswords(pass, globalPassword);
		if (status == MATCHED_PASSWORDS)
		{
			if (key == '-')
			{
				DoorStatus = DOOR_IS_OPENED;
				LCD_Clear();
			}
			else if (key == '+')
			{
				LCD_Clear();
				LCD_goToXY(1, 1);
				LCD_SendString("enter new Pass");
				LCD_goToXY(3, 1);
				setnewPassword();
			}
			else
			{
				/*no Action Required*/
			}
		}
		else if (status == WRONG_PASSWORDS)
		{
			LCD_Clear();
			LCD_SendString("Wrong Password !");
			waitWrongPassword();
			LCD_Clear();
		}
		else
		{
			/*no Action Required*/
		}

	}
	else
	{
		/*no Action Required*/
	}
}
