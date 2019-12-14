/*
 * main.c
 *
 *  Created on: Dec 14, 2019
 *      Author: sayed
 */

#include <avr/io.h>
#include "sevensegment.h"
int main(int argc, char **argv) {
	sevensegment_Init();
	for (unsigned char itr = 0 ; itr <=99 ; itr++){
		sevensegment_BCDupdate(itr);
		_delay_ms(1000);
	}

	while(1){

	}
}

