/*
 * main.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 *      todo : some refactoring in segement enable
 */

#include <avr/io.h>
#include "sevensegment.h"
int main(int argc, char **argv) {
	sevensegment_Init();

	while (1) {

		for (unsigned char itr = 0; itr <= 100; itr++) {
			_delay_ms(70);
			TwoSevensegments_BCDupdate(itr);

		}
	}
}

