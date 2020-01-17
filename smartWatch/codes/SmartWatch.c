/*
 * SmartWatch.c
 *
 *  Created on: Nov 26, 2019
 *      Author: sayed
 */
#include "SmartWatch.h"

/* Task Called Once to initialize all smartWatch Modules */
void smartWatch_initTask(void)
 {

	/* Initialize Port Driver */
	Port_Init(&port_configuration);

	/* Initialize Dio Driver */
	Dio_Init(&DIO_configuration);

	/* Initialize Lcd Driver */
	LCD_Init();

	/* Initialize Adc Driver */
	Adc_init(&Adc_configuration);

	/* Enable External Interrupts On External INT2 pin */
	IU_ExternalInt2_setCallback(incrementAlarmHours);
	IU_ExternalInterruptEnable(&Int2_configuration);

	/* Enable External Interrupts On External INT0 pin */
	IU_ExternalInt0_setCallback(incrementAlarmSeconds);
	IU_ExternalInterruptEnable(&Int0_configuration);

	/* Enable External Interrupts On External INT1 pin */
	IU_ExternalInt1_setCallback(incrementAlarmMinutes);
	IU_ExternalInterruptEnable(&Int1_configuration);

	/* Initialize Gpt Driver */
	Gpt1_OcrSetCallback(tick);
	Timer1_InitoneSecond();

	Gpt2_OcrSetCallback(alarmRuntime);
	/*Enable Global Interrupts */
	sei();
}


/* Task Called Every To update Clock */
void Clock_Task(void)
{
//	updatetime();
	displaytime();
}

/* Task Called Every To Update Date */
void Date_Task(void)
{
	updatedate();
	displaydate();

}
/* Task Called Every To Update Temperature */
void Temperature_Task(void)
{
	updatetemp();
    displaytemp();

}
/* Task Called Every To Check Alarm */
void Alarm_Task(void)
{
//	checkalarm();
	displayalarm();

}
/*Task Called Once To init LCD Display*/
void Display_Task(void)
{
	Clock_Task();
	Date_Task();
	Temperature_Task();
	Alarm_Task();
}
