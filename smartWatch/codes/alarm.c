/*
 * alarm.c
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */

#include "alarm.h"


/*
 * Variables To Hold Alarm time in 24 Mode
 */

volatile uint8 g_Alarmseconds = 0;/*Global Variable To Hold Alarm Seconds Slot */
volatile uint8 g_Alarmminutes = 0;/*Global Variable To Hold Alarm Seconds Slot */
volatile uint8 g_Alarmhours = 0;/*Global Variable To Hold Alarm Seconds Slot */
volatile uint8 g_Alarmstatus = ALARM_NOT_SET;/*Global Variable To Hold Alarm Status*/
volatile uint8 delay = 0 ;/*Global Variable To Hold Delay Time*/

/*
 * Function To Increment Alarm Seconds
 */
void incrementAlarmSeconds()
{
	g_Alarmseconds++;
	if(g_Alarmseconds>=MAX_SECONDS_PER_MINUTE)
	{
		g_Alarmseconds = 0 ;
	}
	g_Alarmstatus=ALARM_SET;
}


/*
 * Function To Increment Alarm Minutes
 */
void incrementAlarmMinutes()
{
	g_Alarmminutes++;
	if (g_Alarmminutes >= MAX_MINUTES_PER_HOUR)
	{
		g_Alarmminutes = 0;
	}
	g_Alarmstatus = ALARM_SET;
}


/*
 * Function To Increment Alarm Hours
 */
void incrementAlarmHours()
{
	g_Alarmhours++;
	if (g_Alarmhours>= MAX_HOURS_PER_DAY)
	{
		g_Alarmhours = 0;
	}
	g_Alarmstatus=ALARM_SET;
}

void alarmRuntime()
{
	delay++;
	if(delay>=MAX_DELAY_TIME)
	{
		disable_alarm();
		delay= 0 ;
	}
}
/*
 * Function To Fire Alarm
 */
void fire_alarm()
{
	Dio_WriteChannel(DioConf_LED_PORT_ID_INDEX, STD_HIGH);

	/* Turn On Alarm For Specific Time*/
	Gpt2_SetOcrValue(120);
	Gpt2_init(&Gpt2_configuration);
	Gpt2_OcrInterruptEnable();
}

/*
 * Function To Disable Alarm
 */
void disable_alarm()
{
	Gpt2_deinit();
	g_Alarmseconds = 0;
	g_Alarmminutes = 0;
	g_Alarmhours = 0;
	g_Alarmstatus = ALARM_NOT_SET;
	Dio_WriteChannel(DioConf_LED_PORT_ID_INDEX, STD_LOW);
}

/*
 * Function To Check Alarm
 */
void checkalarm()
{
	if ((g_Alarmseconds == g_seconds) && (g_Alarmminutes == g_minutes)&& (g_Alarmhours == g_24hours))
	{
		fire_alarm();/* Turn On Alarm */
	}
}

/*
 * Function Called To Set Alarm
 */
void setAlarm(uint8 hours, uint8 minutes, uint8 seconds, uint8 period)
{
	g_Alarmseconds = seconds;
	g_Alarmminutes = minutes;
	g_Alarmhours = hours;
	g_Alarmstatus = ALARM_SET;
}

/*
 * Function To Display Alarm
 */
void displayalarm() {
	/*
	 * Variables To Display Alarm time in 24 Mode on LCD
	 */

	uint8 lcdhours[2];
	uint8 lcdminutes[2];
	uint8 lcdseconds[2];
	lcdhours[0] = g_Alarmhours % 10;
	lcdhours[1] = g_Alarmhours / 10;
	lcdminutes[0] = g_Alarmminutes % 10;
	lcdminutes[1] = g_Alarmminutes / 10;
	lcdseconds[0] = g_Alarmseconds % 10;
	lcdseconds[1] = g_Alarmseconds / 10;

	/* Shift LCD Cursor To Alarm Location On LCD*/
	LCD_goToXY(4, 5);

	/*
	 * Display Alarm
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
