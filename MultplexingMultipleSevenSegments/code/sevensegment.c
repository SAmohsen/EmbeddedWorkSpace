/*
 * sevensegment.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */

#include "sevensegment.h"

void sevensegment_Init() {
	SET_BIT(SEVEN_SEGMENT_ENABLE_PORT_DIR, SEVENSEGMENT1_ENABLE);
	SET_BIT(SEVEN_SEGMENT_ENABLE_PORT_DIR, SEVENSEGMENT1_ENABLE);
#ifdef HIGH_NIBBLE
	SEVEN_SEGMENT_PORT_DIR = 0xF0;
#else
	SEVEN_SEGMENT_PORT_DIR = 0x0F;

#endif
	SET_BIT(SEVEN_SEGMENT_ENABLE_PORT, SEVENSEGMENT1_ENABLE);
	SET_BIT(SEVEN_SEGMENT_ENABLE_PORT, SEVENSEGMENT2_ENABLE);
}
void TwoSevensegments_BCDupdate(uint8 value) {
	uint8_t ones;
	uint8_t tens;
	if (value > 99) {
		ones = 0;
		tens = 0;
	} else {
		ones = value % 10;
		tens = value / 10;
	}

#ifdef HIGH_NIBBLE
	SEVEN_SEGMENT_ENABLE_PORT =(SEVEN_SEGMENT_ENABLE_PORT & 0xC0) | 0x02;
	SEVEN_SEGMENT_PORT = (SEVEN_SEGMENT_PORT &0x0F) | (ones<<4);
	_delay_us(500);
	SEVEN_SEGMENT_ENABLE_PORT = (SEVEN_SEGMENT_ENABLE_PORT & 0xC0) | 0x01;
	SEVEN_SEGMENT_PORT = (SEVEN_SEGMENT_PORT &0x0F) | (tens<<4);
	_delay_us(500);
#else
	SEVEN_SEGMENT_ENABLE_PORT = (SEVEN_SEGMENT_ENABLE_PORT & 0xC0) | 0x02;
	SEVEN_SEGMENT_PORT = (SEVEN_SEGMENT_PORT & 0xF0) | (ones);
	_delay_us(500);
	SEVEN_SEGMENT_ENABLE_PORT = (SEVEN_SEGMENT_ENABLE_PORT & 0xC0) | 0x01;
	SEVEN_SEGMENT_PORT = (SEVEN_SEGMENT_PORT & 0xF0) | (tens);
	_delay_us(500);

#endif

}
