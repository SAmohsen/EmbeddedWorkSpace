/*
 * clock.c
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */
#include "clock.h"

/*
 * Variables To Hold Clock time in 24 Mode
 */
uint8 g_seconds = 50;/*Global Variable To Hold Seconds Slot */
uint8 g_minutes = 59;/*Global Variable To Hold Minutes Slot */
uint8 g_24hours = 23;/*Global Variable To Hold Hours Slot */


/*
 * Function Called Every second To Increment Base Unit Of  Time
 */
void tick()
{
	g_seconds++; /* increment Seconds Time */
	updatetime();
	if(g_Alarmstatus==ALARM_SET)
	{
		checkalarm();
	}
}



/*
 *Function To Update Clock
 */
void updatetime()
{
	if (g_seconds >= MAX_SECONDS_PER_MINUTE)
	{
		g_seconds = 0;
		g_minutes++; /* increment Minutes Count */
		if (g_minutes >= MAX_MINUTES_PER_HOUR)
		{
			g_minutes = 0;
			g_24hours++;/* increment Hours Count */
			if (g_24hours >= MAX_HOURS_PER_DAY)
			{
				g_24hours = 0;
				g_days++;/* increment Days Count */
			}
		}
	}
}


/*
 * Function To Display Clock On LCD
 */

void displaytime() {
	/*
	 * Variables To Display Clock time in 24 Mode on LCD
	 */

	uint8 lcdhours[2];
	uint8 lcdminutes[2];
	uint8 lcdseconds[2];
	lcdhours[0]   = g_24hours % 10;
	lcdhours[1]   = g_24hours / 10;
	lcdminutes[0] = g_minutes % 10;
	lcdminutes[1] = g_minutes / 10;
	lcdseconds[0] = g_seconds % 10;
	lcdseconds[1] = g_seconds / 10;


	/* Shift LCD Cursor To Clock Location On LCD*/
	LCD_goToXY(1, 5);


	/*
	 * Display Clock
	 */
	LCD_SendIntegerData(lcdhours[1]);
	LCD_SendIntegerData(lcdhours[0]);
	LCD_SendU8Data(':');
	LCD_SendIntegerData(lcdminutes[1]);
	LCD_SendIntegerData(lcdminutes[0]);
	LCD_SendU8Data(':');
	LCD_SendIntegerData(lcdseconds[1]);
	LCD_SendIntegerData(lcdseconds[0]);
}
