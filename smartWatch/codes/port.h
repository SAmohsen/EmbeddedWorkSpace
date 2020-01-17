/*
 * port.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef PORT_H_
#define PORT_H_

#include "std_types.h"
#include "common_marcos.h"
#include "port_types.h"
#include "port_cfg.h"

#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)



#define PINS_NUM						(32U)
#define PINS_PER_PORT					(8U)
#define NUMBER_OF_PORTS					(4U)

#define PORTA_ID  0x00
#define PORTB_ID  0x01
#define PORTC_ID  0x02
#define PORTD_ID  0x03


#define PORT_A_START					(0U)
#define PORT_A_FINISH					(7U)

#define PORT_B							(1U)
#define PORT_B_START					(8U)
#define PORT_B_FINISH					(15U)

#define PORT_C							(2U)
#define PORT_C_START					(16U)
#define PORT_C_FINISH					(23U)

#define PORT_D							(3U)
#define PORT_D_START					(24U)
#define PORT_D_FINISH					(31U)

#define PIN_0							(0U)//A
#define PIN_1							(1U)
#define PIN_2							(2U)
#define PIN_3							(3U)
#define PIN_4							(4U)
#define PIN_5							(5U)
#define PIN_6							(6U)
#define PIN_7							(7U)
#define PIN_8							(8U)//B
#define PIN_9							(9U)
#define PIN_10							(10U)
#define PIN_11							(11U)
#define PIN_12							(12U)
#define PIN_13							(13U)
#define PIN_14							(14U)
#define PIN_15							(15U)
#define PIN_16							(16U)//c
#define PIN_17							(17U)
#define PIN_18							(18U)
#define PIN_19							(19U)
#define PIN_20							(20U)
#define PIN_21							(21U)
#define PIN_22							(22U)
#define PIN_23							(23U)
#define PIN_24							(24U)//D
#define PIN_25							(25U)
#define PIN_26							(26U)
#define PIN_27							(27U)
#define PIN_28							(28U)
#define PIN_29							(29U)
#define PIN_30							(30U)
#define PIN_31							(31U)

#define PIN_INPUT 								 (0U)
#define PIN_OUTPUT								 (1U)
#define DEFUALT_PIN_DIR							 PIN_INPUT


/******************************************************************************
 * 							Function prototypes
 * ****************************************************************************/

void Port_Init(const Port_ConfigType *ConfigPtr);
#endif /* PORT_H_ */
