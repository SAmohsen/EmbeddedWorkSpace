/*
 * door.h
 *
 *  Created on: Jan 10, 2020
 *      Author: sayed
 */

#ifndef DOOR_H_
#define DOOR_H_

#include "passwords.h"
#include "LCD.h"
#include "KeyPad.h"
#include "UART.h"
extern uint8 DoorStatus ;
extern uint8 volatile tick ;

#define DOOR_IS_LOCKED 1
#define DOOR_IS_OPENED 0
#define MATCHED_PASSWORDS 1
#define WRONG_PASSWORDS 0
void doorsetup() ;
void doorLoop() ;

#endif /* DOOR_H_ */
