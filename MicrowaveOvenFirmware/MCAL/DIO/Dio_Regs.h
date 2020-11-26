/*
 * Dio_Regss.h
 *
 *  Created on: Feb 16, 2020
 *      Author: SAmohsen
 */

#ifndef MCAL_DIO_DIO_REGS_H_
#define MCAL_DIO_DIO_REGS_H_


#include "../../std_types.h"
#include "../../common_marcos.h"
#include "../../micro_config.h"



/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 * const)0x003B)
#define PINA_REG 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 * const)0x0038)
#define PINB_REG 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 * const)0x0035)
#define PINC_REG 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 * const)0x0032)
#define PIND_REG 	(*(volatile const uint8 * const)0x0030)

#define DIO_OUTPUT_PORT1 PORTA_REG
#define DIO_OUTPUT_PORT2 PORTB_REG
#define DIO_OUTPUT_PORT3 PORTC_REG
#define DIO_OUTPUT_PORT4 PORTD_REG


#define DIO_INPUT_PORT1 PINA_REG
#define DIO_INPUT_PORT2 PINB_REG
#define DIO_INPUT_PORT3 PINC_REG
#define DIO_INPUT_PORT4 PIND_REG



#endif /* MCAL_DIO_DIO_REGS_H_ */
