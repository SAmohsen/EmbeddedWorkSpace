/*
 * leds.c
 *
 *  Created on: Jan 10, 2020
 *      Author: sayed
 */

#include "leds.h"

void roll_leds() {
	PORTB = 0x01;
	while (PORTB != 0) {
		_delay_ms(500);
		PORTB = (PORTB << 1); //every time only one led is ON
	}
}

void turnoffLeds() {
	PORTB = 0x00;
}
