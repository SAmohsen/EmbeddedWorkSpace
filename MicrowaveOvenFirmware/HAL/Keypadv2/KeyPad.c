 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#include "KeyPad.h"

static char keypad_getASCII(uint8 row, uint8 col) {

#ifdef KEYPAD_3X3_MODE
char key_arr[][3]={{'1','2','3'},
				  {'4','5','6'},
                  {'7','8','9'},
                  {'*','0','#'}
                 };

#else
	char key_arr[][4] = { { '7', '8', '9', '/' },
			{ '4', '5', '6', '*' },
			{ '1','2', '3', '-' },
			{ ' ', '0', '=', '+' } };

#endif
	return key_arr[row][col] ;/*return ASCII Value of Pressed Key*/

}


static char keypad_getNumber(uint8 row, uint8 col) {
	uint8 value ;
#ifdef KEYPAD_3X3_MODE
char key_arr[][3]={{'1','2','3'},
				  {'4','5','6'},
                  {'7','8','9'},
                  {'*','0','#'}
                 };

#else
	char key_arr[][4] = { { '7', '8', '9', '/' },
			{ '4', '5', '6', '*' },
			{ '1','2', '3', '-' },
			{ ' ', '0', '=', '+' } };

#endif
	 value = key_arr[row][col] - '0';/*Value of Pressed Key*/
	return value;
}





uint8 Keypad_getPressedKeyASCII() {

	uint8 row;/*loop iterator for keypad rows */
	uint8 col;/*loop iterator for keypad cols */
	uint8 state = KEY_NOT_PRESSED;/*state of a keypad button*/
	/*ground Columns one by one then listen to all rows to capture a pressed key*/
	while (1) {
		for (col = 0; col < NUMBER_OF_COLS; col++)/*loop for columns*/
		{
			/*Rows  Connected On High Nibble Of Keypad Port */
			KEYPAD_DDR = 0b00010000 << col;
			/*ground columns one by one */
			/*internal pull up resistors for keypad row pins */
			KEYPAD_PORT = (~(0b00010000 << col));

			//KEYPAD_DDR =  (KEYPAD_DDR & 0xF0)|(0x01<<col);/*make one column output at time*/
			//KEYPAD_PORT =  KEYPAD_PORT&(~(0x01<<col)) ;/*ground it*/

			for (row = 0; row < NUMBER_OF_ROWS; row++)/*loop for rows*/
			{
				if (BIT_IS_CLEAR(KEYPAD_PIN, row))
				{
					_delay_ms(100);/*software debouncing*/
					if (BIT_IS_CLEAR(KEYPAD_PIN, row))
					{
						state = KEY_PRESSED;
						return keypad_getASCII(row, col);
					}
				}

			}/*end inner for loop*/
		}/*end outer for loop*/
	}/*end while loop*/

}

uint8 Keypad_getPressedKeyValue() {

	uint8 row;/*loop iterator for keypad rows */
	uint8 col;/*loop iterator for keypad cols */
	uint8 state = KEY_NOT_PRESSED;/*state of a keypad button*/
	/*ground Columns one by one then listen to all rows to capture a pressed key*/
	while (1) {
		for (col = 0; col < NUMBER_OF_COLS; col++)/*loop for columns*/
		{
			/*Rows  Connected On High Nibble Of Keypad Port */
			KEYPAD_DDR = 0b00010000 << col;
			/*ground columns one by one */
			/*internal pull up resistors for keypad row pins */
			KEYPAD_PORT = (~(0b00010000 << col));

			//KEYPAD_DDR =  (KEYPAD_DDR & 0xF0)|(0x01<<col);/*make one column output at time*/
			//KEYPAD_PORT =  KEYPAD_PORT&(~(0x01<<col)) ;/*ground it*/

			for (row = 0; row < NUMBER_OF_ROWS; row++)/*loop for rows*/
			{
				if (BIT_IS_CLEAR(KEYPAD_PIN, row))
				{
					_delay_ms(100);/*software debouncing*/
					if (BIT_IS_CLEAR(KEYPAD_PIN, row))
					{
						state = KEY_PRESSED;
						return keypad_getNumber(row, col);
					}
				}

			}/*end inner for loop*/
		}/*end outer for loop*/
	}/*end while loop*/

}
