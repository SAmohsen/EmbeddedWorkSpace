 /******************************************************************************
 *
 * Module: SYS
 *
 * File Name: sys.c
 *
 * Description: Source file For Microwave Oven System
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/

#include "SYS.h"



/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
static volatile uint8 timeArr[4];/*Global Variable To display Time Required On Screen  */
/*
 * Assuming Max Time Is 60 Minutes With Format MM:SS
 * EX : time is set To 23:50
 * timeArr[0] = 2 ;
 * timeArr[1] = 3 ;
 * timeArr[2] = 5 ;
 * timeArr[3] = 0 ;
 */
static volatile uint8 minutes=0 ;/*Global Variable To Hold required Time Minutes*/
static volatile uint8 seconds=0;/*Global Variable To Hold required Time seconds*/
static volatile uint16 requiredtime = 0; /* Global Variable To Hold Total Time Required In Seconds */
static volatile uint8 timerflag =TIME_IS_NOT_SET ;/* Global Variable to Hold Timer Status*/
static volatile uint8 doorstatus = DOOR_IS_OPENED;/*Global Variable To Hold Door Sensor Status */
static volatile uint8 foodstatus = THERE_IS_NO_FOOD_INSID_MICROWAVE ; /*Global Variable To Hold Weight SensorStatus */
static volatile uint8 microwavestatus = MICROWAVE_IDLE;/*Global Variable To current microwave status */


/**************************************************************************************
 * 							Function ProtoTypes										*
 * ************************************************************************************/
static void MICROWAVE_displayTime();
static void MICROWAVE_setCookingTime();
static void MICROWAVE_displayHomeScreen();
static void MICROWAVE_CalculateTotalTimeRequired();
static void MICROWAVE_toggleDoorState();
static void MICROWAVE_toggleFoodState();
static void MICROWAVE_stopCooking();
static void MICROWAVE_startCooking();
static void MICROWAVE_clearTimeSettings();
static void MICROWAVE_updateTime();
static void MICROWAVE_cancelOperation();


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/




/************************************************************************************
* Service Name: MICROWAVE_displayTime
* Parameters (in): None
* Return value: None
* Description: Function to Display Cooking Time On Screen.
************************************************************************************/

static void MICROWAVE_displayTime()
{
	LCD_goToXY(2, 4);/*Go To Timer Location On Screen*/
	/*
	 * Display Minutes
	 */
	LCD_SendU32Data(timeArr[0]);
	LCD_SendU32Data(timeArr[1]);
	LCD_SendU8Data(':');
	/*
	 * Display Seconds
	 */
	LCD_SendU32Data(timeArr[2]);
	LCD_SendU32Data(timeArr[3]);

}



/************************************************************************************
* Service Name: MICROWAVE_takeCookingTime
* Parameters (in): None
* Return value: None
* Description: Function to Take Cooking Time From User And Display it On Screen.
************************************************************************************/
static void MICROWAVE_setCookingTime()
{
	LCD_goToXY(2, 4);/*Go To Timer Location On Screen*/
	timeArr[0] = Keypad_getPressedKeyValue();/*Take Minutes Tens Value From User*/
	LCD_SendU32Data(timeArr[0]);
	timeArr[1] = Keypad_getPressedKeyValue();/*Take Minutes Ones Value From User*/
	LCD_SendU32Data(timeArr[1]);
	LCD_goToXY(2, 7);
	timeArr[2] = Keypad_getPressedKeyValue();/*Take Seconds Tens Value From User*/
	LCD_SendU32Data(timeArr[2]);
	timeArr[3] = Keypad_getPressedKeyValue();/*Take  Seconds Ones Value From User*/
	LCD_SendU32Data(timeArr[3]);
	timerflag = TIME_IS_SET;/*Set Timer Flag*/
}


/************************************************************************************
* Service Name: MICROWAVE_displayHomeScreen
* Parameters (in): None
* Return value: None
* Description: Function to display Home Screen.
************************************************************************************/
static void MICROWAVE_displayHomeScreen()
{
	//LCD_Clear();
	MICROWAVE_displayTime();

#if 0
	LCD_SendString("Set Time");
	LCD_goToXY(2, 4);/*Go To Timer Location On Screen*/
	LCD_SendString("MM:SS");/*Display Cooking Time Format*/
#endif
}

/************************************************************************************
* Service Name: MICROWAVE_CalculateTotalTimeRequired
* Parameters (in): None
* Return value: None
* Description: Function to Calculate Total Time Required In Seconds.
************************************************************************************/

static void MICROWAVE_CalculateTotalTimeRequired()
{
	minutes = (timeArr[0] * 10) + timeArr[1] ;
	seconds = (timeArr[2] * 10)+ timeArr[3];
	requiredtime = (minutes * 60)+ seconds ;
	//requiredtime = (((timeArr[0] * 10) + timeArr[1]) * 60) + (timeArr[2] * 10)+ timeArr[3];
}



/************************************************************************************
* Service Name: MICROWAVE_setDoorState
* Parameters (in): None
* Return value: None
* Description: Function to Toggle Door State  based on readings from Door Sensor.
************************************************************************************/

static void MICROWAVE_toggleDoorState()
{
	if(DOOR_IS_CLOSED==doorstatus)
	{
		doorstatus = DOOR_IS_OPENED ;
	}
	else if (DOOR_IS_OPENED==doorstatus)
	{
		doorstatus=DOOR_IS_CLOSED ;
	}
	else
	{
		/* No Action Required*/
	}
}




/************************************************************************************
* Service Name: MICROWAVE_setFoodState
* Parameters (in): None
* Return value: None
* Description: Function to Toggle Food State  based on readings from Weight Sensor.
************************************************************************************/

static void MICROWAVE_toggleFoodState()
{
	if(THERE_IS_NO_FOOD_INSID_MICROWAVE==foodstatus)
	{
		foodstatus = THERE_IS_FOOD_INSID_MICROWAVE ;
	}
	else if (THERE_IS_FOOD_INSID_MICROWAVE==foodstatus)
	{
		foodstatus=THERE_IS_NO_FOOD_INSID_MICROWAVE ;
	}
	else
	{
		/* No Action Required*/
	}
}


/************************************************************************************
* Service Name: MICROWAVE_stopCooking
* Parameters (in): None
* Return value: None
* Description: Function to Stop Cooking Food Inside Microwave.
************************************************************************************/

static void MICROWAVE_stopCooking()
{
	Timer1_deInit();/*Stop Timer*/
	timerflag = TIME_IS_NOT_SET;/*Clear Timer Flag*/
	MICROWAVE_clearTimeSettings();/*clear Time Settings*/
	Heater_off();/*Turn Off Heater*/
	Lamp_off();/*Turn Off Lamp*/
	DCMotor_Stop();/*Stop the Motor*/
	microwavestatus=MICROWAVE_IDLE;/*Update Microwave status*/
}


/************************************************************************************
* Service Name: MICROWAVE_startCooking
* Parameters (in): None
* Return value: None
* Description: Function to Start Cooking Food Inside Microwave.
************************************************************************************/

static void MICROWAVE_startCooking()
{
	MICROWAVE_CalculateTotalTimeRequired();/*Calculate Total Time Required In seconds*/
	if(requiredtime>0)/*Start Cooking Only If Required Time larger Than Zero*/
	{
		Timer1_InitoneSecond();/*Initialize Timer*/
		Heater_on();/*Turn on Heater*/
		Lamp_on();/*Turn On Lamp*/
		DCMotor_RotateClockwise();/*Rotate Motor*/
		microwavestatus=MICROWAVE_IS_HEATING;/*Update Microwave status*/
		while (requiredtime != 0)/*Wait Until Microwave Stop Cooking*/
		{
			MICROWAVE_displayTime();/*display time*/
		}
	}
	else
	{
		MICROWAVE_clearTimeSettings();
	}
}

/************************************************************************************
* Service Name: MICROWAVE_clearTimeSettings
* Parameters (in): None
* Return value: None
* Description: Function To Clear Time Settings.
************************************************************************************/

static void MICROWAVE_clearTimeSettings()
{
	uint8 itr = 0 ;
	requiredtime = 0;/* Clear required Time */
	timerflag = TIME_IS_NOT_SET;/*Clear Timer Flag*/
	while(itr<4)
	{
		timeArr[itr] = 0 ;/* Clear Timer Array*/
		itr++;
	}
}

/************************************************************************************
* Service Name: MICROWAVE_cancelOperation
* Parameters (in): None
* Return value: None
* Description: Functionality For Cancel Button.
************************************************************************************/

static void MICROWAVE_cancelOperation()
{
	if(MICROWAVE_IS_HEATING==microwavestatus)
	{
		MICROWAVE_stopCooking();/*Stops Cooking If Heating Is on*/
	}
	else
	{
		MICROWAVE_clearTimeSettings();/* clear Time Settings */
	}
}

/************************************************************************************
* Service Name: MICROWAVE_updateTime
* Parameters (in): None
* Return value: None
* Description: Function To update Time.
************************************************************************************/

static void MICROWAVE_updateTime()
{
	minutes = requiredtime / 60 ;
	seconds = requiredtime -  (minutes * 60) ;
	timeArr[0] = minutes / 10;
	timeArr[1] = minutes % 10;
	timeArr[2] = seconds / 10 ;
	timeArr[3] = seconds %10;
}

void tick()
{
	requiredtime--;
	MICROWAVE_updateTime();
	if (requiredtime == 0)
	{
		MICROWAVE_stopCooking();

	}
}


void debug()
{
	LCD_goToXY(4,1);
	LCD_SendU32Data(doorstatus);
	LCD_SendU32Data(timerflag);
	LCD_SendU32Data(foodstatus);
	LCD_SendU32Data(microwavestatus);
	LCD_SendU8Data('-');
	LCD_SendU32Data(requiredtime);

}

/************************************************************************************
* Service Name: SYS_init
* Parameters (in): None
* Return value:None
* Description: Function to Initialize System.
************************************************************************************/

void SYS_init()
{
	LCD_Init();/*Initialize Door Status*/

	/*Initialize Cancel button */
	IU_ExternalInt0_setCallback(MICROWAVE_cancelOperation);
	IU_ExternalInterruptEnable(&Int0_configuration);

	/*Initialize Door Sensor*/
	IU_ExternalInterruptEnable(&Int1_configuration);
	IU_ExternalInt1_setCallback(MICROWAVE_toggleDoorState);

	/*Initialize Food Sensor*/
	IU_ExternalInt2_setCallback(MICROWAVE_toggleFoodState);
	IU_ExternalInterruptEnable(&Int2_configuration);

	/*Initialize Start Button*/
	//PORT_setPinDirection(PORT_PD,PIN_1,PORT_PIN_IN);
	BUTTON_init();

	/*Set Time CallBack Function*/
	Gpt1_OcrSetCallback(tick);

	/* initialize DC Motor*/
	DCMotor_Init();

	/*Initialize Heater*/
	Heater_init();

	/*initialize Lamp*/
	Lamp_init();

	/*Enable global Interrupts*/
	sei();

   /*Display Home Screen*/
	MICROWAVE_displayHomeScreen();

}

/************************************************************************************
* Service Name: SYS_start
* Parameters (in): None
* Return value:None
* Description: Function to run System.
************************************************************************************/

void SYS_start() {
	while (1) {
		debug();
		MICROWAVE_displayTime();
		if (TIME_IS_NOT_SET == timerflag) {
			MICROWAVE_setCookingTime();
		}

		if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW) {
			_delay_ms(60);
			if (Dio_readPinValue(BUTTON_PORT, BUTTON_PIN) == STD_LOW) {
				if ((TIME_IS_SET == timerflag)
						&& (THERE_IS_FOOD_INSID_MICROWAVE == foodstatus)
						&& (DOOR_IS_CLOSED == doorstatus)) {
					MICROWAVE_startCooking();

				}
			}

		}

	}
}
#if 0
if (BUTTON_IS_PRESSED==BUTTON_ReadState())
{
	if((TIME_IS_SET==timerflag)&&(THERE_IS_FOOD_INSID_MICROWAVE==foodstatus)&&(DOOR_IS_CLOSED==doorstatus))
	{
		MICROWAVE_startCooking();

	}


#endif
