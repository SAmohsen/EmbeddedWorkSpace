/*
 * temperature.c
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */
#include "temperature.h"


static uint16 g_temp;/* global Variable To Hold Temperature*/

/*
 * Function To Update Temperature
 */
void updatetemp()
{
	g_temp = LM35_ReadTemp();
}

/*
 * Function To Display Temperature On LCD
 */
void displaytemp()
{
	/*
	 * Shift LCD cursor To Temperature Location On LCD
	 */
	LCD_goToXY(3, 4);

	/*
	 * Display Temperature
	 */
	LCD_SendString("temp :");
	LCD_SendIntegerData(g_temp);
	LCD_SendU8Data(0xDF);
	LCD_SendString("C");
}
