/*
 * DIO_REGS.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef DIO_REGS_H_
#define DIO_REGS_H_

#include "std_types.h"

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


#endif /* DIO_REGS_H_ */
