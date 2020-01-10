/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "std_types.h"
#include "common_marcos.h"

#include "KeyPad_cfg.h"

/* Keypad configurations for number of rows and columns */
#ifdef KEYPAD_3X3_MODE
#define NUMBER_OF_COLS 3
#define NUMBER_OF_ROWS 4

#else
#define NUMBER_OF_COLS 4
#define NUMBER_OF_ROWS 4
#endif

/*keypad Button State Configuration*/
#define KEY_PRESSED 1
#define KEY_NOT_PRESSED 0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
uint8 Keypad_getPressedKey(void);
#endif /* HAL_KEYPAD_KEYPAD_H_ */
