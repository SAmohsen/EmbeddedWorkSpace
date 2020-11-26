 /******************************************************************************
 *
 * Module: SYS
 *
 * File Name: sys.H
 *
 * Description: Header file For Microwave Oven System
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/

#ifndef SYS_H_
#define SYS_H_

#include "main.h"
#include "HAL/LCDv2/LCD.h"
#include "HAL/Keypadv2/KeyPad.h"
#include "HAL/Lamp/Lamp.h"
#include "HAL/Heater/Heater.h"
#include "HAL/MOTORS/DCMotor.h"
#include "HAL/Button/Button.h"
#include "MCAL/GPT/GPT.h"
#include "MCAL/Interrupts/interrupts.h"
#include "MCAL/Interrupts/Interrupts_PBcfg.h"
#include "MCAL/PORT/port.h"
#include "MCAL/DIO/Dio.h"

/**************************************************************************************
 * 							Preprocessor Macros										*
 * ************************************************************************************/

/*
 * Macros For Door sensor Status
 */
#define DOOR_IS_OPENED 0
#define DOOR_IS_CLOSED 1

/*
 * Macros For Weight sensor Status
 */
#define THERE_IS_FOOD_INSID_MICROWAVE 1
#define THERE_IS_NO_FOOD_INSID_MICROWAVE 0

/*
 * Macros For Timer Status
 */
#define TIME_IS_NOT_SET 0
#define TIME_IS_SET 1

/*
 * Macros For Microwave status
 */
#define MICROWAVE_IDLE 0
#define MICROWAVE_IS_HEATING 1


/**************************************************************************************
 * 							Function ProtoTypes										*
 * ************************************************************************************/

void SYS_init();/* Description: Function to Initialize System.*/
void SYS_start();/* Description: Function to run System.*/

#endif /* SYS_H_ */
