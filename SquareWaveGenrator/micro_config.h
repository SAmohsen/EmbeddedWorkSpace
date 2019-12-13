/*
 * micro_config.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifdef F_CPU
#undef F_CPU
#define F_CPU 1000000UL /*1 Mhz clock Frequency */
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* MICRO_CONFIG_H_ */
