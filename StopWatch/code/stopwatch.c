/*
 * stopwatch.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */
#include "stopwatch.h"

static uint8 tick = 0;
static uint16 g_seconds = 0;
static uint16 g_minutes = 0;
static uint16 g_24hours = 0;

ISR(INT0_vect) {
	g_seconds = 0;
	g_minutes = 0;
	g_24hours = 0;
}
void Int0_Init() {
	/*external interrupts setup */
	DDRD &= ~(1 << 2); // configure pinD2asinput pin
	PORTD |= (1 << 2); // enable pull up
	MCUCR |= (1 << ISC01); //Falling edge interrupt sense
	GICR |= (1 << INT0); // external interrupt on pin

}

void enable_globalInterrupts() {
	SREG = (1 << 7);
}

ISR(TIMER0_COMP_vect) {
	tick++;
	if (NUMBER_OF_MATCHES_PER_ONE_SECOND == tick) {
		g_seconds++;
		tick = 0;
	}
}
void timer0_InitCtcmode() {
	TCNT0 = 0; //timer initial value
	/*
	 * F_cpu == 1000000hz
	 * F_timer = 1000000Hz/1024
	 * t_timer = 1024/1000000hz
	 * 1 sec = 1024/1000000hz * count
	 * count = 1000000/1024 = 977
	 * to count 1 sec we will count till top four times
	 * */
	OCR0 = 244;

	TIMSK |= (1 << OCIE0); //enable compare interrupt
	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1 << FOC0) | (1 << WGM01) | (1 << CS02) | (1 << CS00);
}

void displaytime() {
	uint8 lcdhours[2];
	uint8 lcdminutes[2];
	uint8 lcdseconds[2];
	lcdhours[0] = g_24hours % 10;
	lcdhours[1] = g_24hours / 10;
	lcdminutes[0] = g_minutes % 10;
	lcdminutes[1] = g_minutes / 10;
	lcdseconds[0] = g_seconds % 10;
	lcdseconds[1] = g_seconds / 10;

	// out the number of seconds
	PORTA = (PORTA & 0xC0) | 0x01;
	PORTC = (PORTC & 0xF0) | (lcdseconds[0]);

	// make small delay to see the changes in the 7-segment
	// 2Miliseconds delay will not effect the seconds count
	_delay_ms(2);

	PORTA = (PORTA & 0xC0) | 0x02;
	PORTC = (PORTC & 0xF0) | (lcdseconds[1]);

	_delay_ms(2);

	// out the number of minutes
	PORTA = (PORTA & 0xC0) | 0x04;
	PORTC = (PORTC & 0xF0) | (lcdminutes[0]);

	_delay_ms(2);

	PORTA = (PORTA & 0xC0) | 0x08;
	PORTC = (PORTC & 0xF0) | (lcdminutes[1]);

	_delay_ms(2);

	// out the number of hours
	PORTA = (PORTA & 0xC0) | 0x10;
	PORTC = (PORTC & 0xF0) | (lcdhours[0]);

	_delay_ms(2);

	PORTA = (PORTA & 0xC0) | 0x20;
	PORTC = (PORTC & 0xF0) | (lcdhours[1]);

	_delay_ms(2);

}
void updatetime() {
	if (g_seconds >= MAX_SECONDS_PER_MINUTE) {
		g_seconds = 0;
		g_minutes++;
		if (g_minutes >= MAX_MINUTES_PER_HOUR) {
			g_minutes = 0;
			g_24hours++;
			if (g_24hours >= MAX_HOURS_PER_DAY) {
				g_24hours = 0;
			}
		}
	}

}

void setup() {
	enable_globalInterrupts();
	timer0_InitCtcmode();
	Int0_Init();
	// configure INT0/PD2 as input pin
	DDRD &= (~(1 << PD2));
	// enable internal pull up resistor at INT0/PD2 pin
	PORTD |= (1 << PD2);

	// configure first 6 pins in PORTA as output pins
	DDRA |= 0x3F;

	// configure first four pins of PORTC as output pins
	DDRC |= 0x0F;

	// initialize all the 7-segment with zero value
	PORTA |= 0x3F;
	PORTC &= 0xF0;

}
void loop() {
	updatetime();
	displaytime();
}
