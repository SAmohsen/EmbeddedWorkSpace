/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
#include "LCD.h"

static void LCD_trigger() {
	/*Triggering LCd By Sending A high to low Pulse*/
	SET_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
	CLR_BIT(LCD_CONTROL_PORT, LCD_E);
	_delay_ms(1);
}

void LCD_Init() {
	SET_BIT(LCD_CONTROL_DDR, LCD_RS);
	SET_BIT(LCD_CONTROL_DDR, LCD_E);
	SET_BIT(LCD_CONTROL_DDR, LCD_RW);

#ifdef LCD_4BIT_MODE
#ifdef HIGH_NIBBLE
	LCD_DATA_DDR |= 0xF0;
#else
		LCD_DATA_DDR |= 0x0F ;
#endif
	LCD_SendCommand(FOUR_BITS_DATA_MODE);
	LCD_SendCommand(TWO_LINE_LCD_Four_BIT_MODE);

#else
	LCD_DATA_DDR = 0xFF ;
	LCD_SendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
#endif
	LCD_Clear();
	LCD_SendCommand(CURSOR_OFF);
}

void LCD_SendCommand(Lcd_CommandType command) {
	CLR_BIT(LCD_CONTROL_PORT,LCD_RS);/*Select Command Register*/
	CLR_BIT(LCD_CONTROL_PORT, LCD_RW);/*writing in LCD*/
#ifdef LCD_4BIT_MODE
#ifdef HIGH_NIBBLE
	/*send high nibble of command first then send low nibble*/
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F) << 4);
	LCD_trigger();
#else
	/*send high nibble of command first then send low nibble*/
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((command & 0xF0)>>4);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
	LCD_trigger();

#endif
#else
	LCD_DATA_PORT = command ;
	LCD_trigger();
#endif

}
void LCD_SendU8Data(Lcd_DataType data) {
	SET_BIT(LCD_CONTROL_PORT,LCD_RS);/*Select Data Register*/
	CLR_BIT(LCD_CONTROL_PORT, LCD_RW);/*Writing In LCD*/
#ifdef LCD_4BIT_MODE
#ifdef HIGH_NIBBLE
	/*send high nibble of data first then send low nibble*/
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
	LCD_trigger();
#else
	/*send high nibble of data first then send low nibble*/
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((data & 0xF0)>>4);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
	LCD_trigger();

#endif
#else
	LCD_DATA_PORT = data ;
	LCD_trigger();
#endif

}
void LCD_SendString(char *str) {
	uint8 itr = 0;
	while (str[itr] != '\0') {
		LCD_SendU8Data(str[itr]);
		itr++;
	}
}
void LCD_goToXY(uint8 x, uint8 y) {
	/*LCD Commands to set cursor in a specific line
	 *
	 * command = ramAddress | 80--> From DataSheet
	 * addresses :-
	 * 1st line : 0x00
	 * 2nd line : 0x40
	 * 3rd line :0x10
	 * 4rth line :0x50
	 *
	 * commands :-
	 * shift Cursor for 1st  line = 0x00 | 0x80 = 0x80
	 * shift Cursor for 2nd  line = 0x40 | 0x80 = 0xC0
	 * shift Cursor for 3rd  line = 0x10 | 0x80 = 0x90
	 * shift Cursor for 4rth line = 0x50 | 0x80 = 0xD0
	 * */
	uint8 lcd_addr[] = { 0x80, 0xC0, 0x90, 0xD0 };
	uint8 lcd_desired_address = lcd_addr[x - 1] + y;
	LCD_SendCommand(lcd_desired_address);
}
void LCD_Clear(void) {
	LCD_SendCommand(CLEAR_COMMAND);
}
void LCD_shiftDisplayLeft(){
	LCD_SendCommand(SHIFT_DISPLAY_LEFT);
}
void LCD_shiftDisplayRight(){
	LCD_SendCommand(SHIFT_DISPLAY_RIGHT);
}
void LCD_SendIntegerData(int data) {
	char buffer[20];
	itoa(data, buffer, 10);
	LCD_SendString(buffer);

}
static void reverseString(char *str,uint8 len) {
	uint8 right = len - 1;
	uint8 left = 0;
	char tempCharacter;
	while (left < right) {
		tempCharacter = str[left];
		str[left] = str[right];
		str[right] = tempCharacter;
		left++;
		right--;
	}
}
static void integerToASCII(int num, char buffer[]) {
	/*
	 * basic implementation of itoa
	 *
	 *ASCII code	48	0	(number zero)
	 *ASCII code	49	1	(number one)
	 *ASCII code	50	2	(number two)
	 *ASCII code	51	3	(number three)
	 *ASCII code	52	4	(number four)
	 *ASCII code	53	5	(number five)
	 *ASCII code	54	6	(number six)
	 *ASCII code	55	7	(number seven)
	 *ASCII code	56	8	(number eight)
	 *ASCII code	57	9	(number nine)
	 *
	 */
	char ascii_arr[] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
	uint8 itr = 0;
	uint8 tempNumber;
	if (num == 0) {
		buffer[0] = ascii_arr[0];
		itr++;
	} else {
		while (num != 0) {
			tempNumber = num % 10;
			buffer[itr] = ascii_arr[tempNumber];
			itr++;
			num = num / 10;
		}
	}
	reverseString(buffer, itr);
}

void LCD_sendu32Data(int data){
	char buffer[16]={'\0'};
	integerToASCII(data , buffer);
	LCD_SendString(buffer);
}

