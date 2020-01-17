/*
 * date.c
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#include "date.h"


/*
 * Variables To Hold Date
 */

uint8 g_days = 26;  /* global Variable To Hold Days Count */
uint8 g_months = 11;/* global Variable To Hold Months Count */
uint8 g_years = 19; /* global Variable To Hold Years Count */


/*
 *Function To Update Date
 */

void updatedate()
{
	if (g_days >= MAX_DAYS_PER_MONTHS)
	{
		g_days = 1;
		g_months++; /* Increment Months Count */
		if (g_months >= MAX_MONTHS_PER_YEAR)
		{
			g_months = 1;
		}
	}
}


/*
 * Function To Display Date On LCD
 */
void displaydate()
{
	/*
	 * Variables To Display Date on LCD
	 */
	uint8 lcdday[2];
	uint8 lcdmonth[2];
	uint8 lcdyear[4];
	lcdday[0] = g_days % 10;
	lcdday[1] = g_days / 10;
	lcdmonth[0] = g_months % 10;
	lcdmonth[1] = g_months / 10;
	lcdyear[0] = g_years % 10;
	lcdyear[1] = g_years / 10;
	lcdyear[2] = 0;
	lcdyear[3] = 2;

	/* Shift LCD Cursor To Clock Location On LCD*/
	LCD_goToXY(2, 4);

	/* Display Date*/
	LCD_SendIntegerData(lcdday[1]);
	LCD_SendIntegerData(lcdday[0]);
	LCD_SendU8Data('-');
	LCD_SendIntegerData(lcdmonth[1]);
	LCD_SendIntegerData(lcdmonth[0]);
	LCD_SendU8Data('-');
	LCD_SendIntegerData(lcdyear[3]);
	LCD_SendIntegerData(lcdyear[2]);
	LCD_SendIntegerData(lcdyear[1]);
	LCD_SendIntegerData(lcdyear[0]);
}
