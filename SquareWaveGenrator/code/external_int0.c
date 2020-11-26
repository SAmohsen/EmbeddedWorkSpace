/*
 * external_int0.c
 *
 *  Created on: Dec 13, 2019
 *      Author: sayed
 */

#include "external_int0.h"
void Int0_Init() {
	/*external interrupts setup */

	DDRD &= ~(1 << 2); // configure pinD2asinput pin
	PORTB |= (1 << 2); // enable pull up
	MCUCR |= (1 << ISC01); //Falling edge interrupt sense
	GICR |= (1 << INT0); // external interrupt on pin

}
void Int1_Init() {
	DDRD &= ~(1 << 3); // configure pinD3asinput pin
	PORTB |= (1 << 3); // enable pull up
	MCUCR |= (1 << ISC11); //Falling edge interrupt sense
	GICR |= (1 << INT1); // external interrupt on pin 0
}
void enable_globalInterrupts() {
	SREG = (1 << 7);
}
ISR(INT0_vect) {
	if (OCR0==255){
		OCR0 = 0 ;
	}
	OCR0 += 1;
}
ISR(INT1_vect) {
	if (OCR0!=0){
		OCR0 -= 1;
	}

}
