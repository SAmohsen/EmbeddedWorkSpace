/*
 * timer0.c
 *
 *  Created on: Dec 13, 2019
 *      Author: sayed
 */
#include "timer0.h"
void timer0_squareWaveCTCInit(){
	TCNT0 = 0; // initial value 0
	OCR0 = 200; // compare value : initial value
	DDRB = DDRB | (1<<PB3); // OC0 Pin as output pin
	/*
	 * F_timer = F_CPU
	 * compare match mode with oc0 connected
	 * toggle OC0 on compare match
	 * */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);

}
