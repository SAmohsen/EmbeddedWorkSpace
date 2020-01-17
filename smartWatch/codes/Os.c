/*
 * Os.c
 *
 *  Created on: Jan 16, 2020
 *      Author: sayedMohsen
 */

#include "Os.h"

/* Global variable store the Os Time */
static volatile  uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static volatile uint8 g_New_Time_Tick_Flag = 0;


/* Function responsible for:
 * 1. Initialize the Os
 * 2. Execute the Init Task
 * 3. Start the Scheduler to run the tasks
 */
void Os_start(void) {

	/*
	 * Set the Call Back function call to Scheduler_New_Timer_Tick
	 * this function will be called every Timer0 Compare Interrupt(20ms)
	 */

	Gpt0_OcrSetCallback(Os_newTimerTick);

	/* Start Timer0 in Compare Mode to generate interrupt every 20ms */
	Gpt0_init(&Gpt0_configuration);
	Gpt0_SetOcrValue(OS_BASE_TIME);
	Gpt0_OcrInterruptEnable();

	/* Execute the Init Task */
	smartWatch_initTask();


	Display_Task();
	/* Start the Os Scheduler */
	Os_scheduler();


}



/* Function called by the Timer Driver in the MCAL layer using the call back pointer */
void Os_newTimerTick(void)
{

	if (g_Time_Tick_Count==120)
	{
		g_Time_Tick_Count=0;
	}
	//LCD_goToXY(2,1);
			//LCD_sendu32Data(g_Time_Tick_Count);


	/* increment the Os time by OS_BASE_TIME */
	g_Time_Tick_Count   += OS_BASE_TIME;

	/* Set the flag to 1 to indicate that there is a new timer tick */
	g_New_Time_Tick_Flag = 1;

}

/* The Engine of the Os Scheduler used for switch between different tasks */
void Os_scheduler(void) {
	while (1){
		/* Code is only executed in case there is a new timer tick */
		if (g_New_Time_Tick_Flag == 1) {
			switch (g_Time_Tick_Count) {
			case 20:
				Clock_Task();
				g_New_Time_Tick_Flag = 0;
				break;
			case 40:
				Clock_Task();
				Alarm_Task();
				g_New_Time_Tick_Flag = 0;
				break;
			case 60:
				//Dio_WriteChannel(DioConf_LED_PORT_ID_INDEX, STD_LOW);
				Clock_Task();
				Temperature_Task();
				g_New_Time_Tick_Flag = 0;
				break;
			case 80:
				Clock_Task();
				Alarm_Task();
				g_New_Time_Tick_Flag = 0;
				break;

			case 100:
				Clock_Task();
				Date_Task();
				g_New_Time_Tick_Flag = 0;
				break;
			}
		}
	}

}

