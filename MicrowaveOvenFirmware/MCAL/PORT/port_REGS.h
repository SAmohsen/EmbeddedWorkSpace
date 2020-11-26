/*
 * port_REGS.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef PORT_REGS_H_
#define PORT_REGS_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include"../../micro_config.h"


/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 * const)0x003B)
#define DDRA_REG	(*(volatile uint8 * const)0x003A)
#define PINA_REG 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 * const)0x0038)
#define DDRB_REG	(*(volatile uint8 * const)0x0037)
#define PINB_REG 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 * const)0x0035)
#define DDRC_REG	(*(volatile uint8 * const)0x0034)
#define PINC_REG 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 * const)0x0032)
#define DDRD_REG	(*(volatile uint8 * const)0x0031)
#define PIND_REG 	(*(volatile const uint8 * const)0x0030)



#define DIO_OUTPUT_PORT1 PORTA_REG
#define DIO_OUTPUT_PORT2 PORTB_REG
#define DIO_OUTPUT_PORT3 PORTC_REG
#define DIO_OUTPUT_PORT4 PORTD_REG


#define DIO_INPUT_PORT1 PINA_REG
#define DIO_INPUT_PORT2 PINB_REG
#define DIO_INPUT_PORT3 PINC_REG
#define DIO_INPUT_PORT4 PIND_REG

#define DIO_PORT1_DIRECTION DDRA_REG
#define DIO_PORT2_DIRECTION DDRB_REG
#define DIO_PORT3_DIRECTION DDRC_REG
#define DIO_PORT4_DIRECTION DDRD_REG


#endif /* PORT_REGS_H_ */
