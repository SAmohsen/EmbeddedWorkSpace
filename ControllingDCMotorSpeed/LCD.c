/*
 * LCD.c
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */


#include "LCD.h"

static void LCD_trigger(){
	SET_BIT(LCD_CONTROL_PORT,LCD_E) ;
	_delay_ms(1);
	CLR_BIT(LCD_CONTROL_PORT,LCD_E);
	_delay_ms(1);
}

void LCD_Init(){
	SET_BIT(LCD_CONTROL_DDR,LCD_RS);
	SET_BIT(LCD_CONTROL_DDR,LCD_E);
	SET_BIT(LCD_CONTROL_DDR,LCD_RW);
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
	LCD_SendCommand(CURSOR_ON);
	LCD_SendCommand(CURSOR_OFF);
}

void LCD_SendCommand(Lcd_CommandType command){
	CLR_BIT(LCD_CONTROL_PORT,LCD_RS) ;
	CLR_BIT(LCD_CONTROL_PORT,LCD_RW);
#ifdef LCD_4BIT_MODE
#ifdef HIGH_NIBBLE
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F)<<4);
	LCD_trigger();
#else
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
void LCD_SendU8Data(Lcd_DataType data){
	SET_BIT(LCD_CONTROL_PORT,LCD_RS) ;
	CLR_BIT(LCD_CONTROL_PORT,LCD_RW);
#ifdef LCD_4BIT_MODE
#ifdef HIGH_NIBBLE
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
	LCD_trigger();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F)<<4);
	LCD_trigger();
#else
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
void LCD_SendString(char * str){
	uint8 itr = 0 ;
	while (str[itr]!='\0'){
		LCD_SendU8Data(str[itr]) ;
		itr++ ;
	}
}
void LCD_goToXY(uint8 x, uint8 y){
uint8 lcd_addr [] = {0x80 , 0xC0 , 0x94 ,0x80} ;
uint8 lcd_desired_address = lcd_addr[x-1] + y ;
LCD_SendCommand(lcd_desired_address);
}
void LCD_Clear(void){
	LCD_SendCommand(CLEAR_COMMAND);
}

void LCD_SendIntegerData(int data){
char buffer [20];
itoa(data,buffer,10);
LCD_SendString(buffer);

}

/*
void LCD_SendIntegerData(int data){
char buffer [20];
if (data<0)
{
LCD_SendU8Data('-');
}
else
{

}
{
IntegerToStr(data,buffer);
LCD_SendString(buffer);
}
}

#define MAX_INTEGER_DIGITS 3
#define MAX_INTEGER_NUMBER 999


static uint8 getstringlength(char *str) {
	uint8 counter = 0;
	while (str[counter] != 0) {
		counter++;
	}
	return counter;
}


static void reverseString (char *str){
uint8 len = getstringlength(str);
uint8 right = len-1 ;
uint8 left =0;
char tempCharacter;
while (left<right){
	tempCharacter = str[left];
	str[left]=str[right];
	str[right]=tempCharacter;
	left++;
	right--;
}
}
static void IntegerToStr(int num, char buffer[]){
	*
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
	 *
	char ascii_arr [] = {48,49,50,51,52,53,54,55,56,57};
	uint8 itr =0 ;
	uint8 tempNumber ;
	if (num<0)
	{
	num  = num *-1;
	}
	while (num !=0){
		tempNumber = num%10 ;
		buffer[itr] = (char)ascii_arr[tempNumber];
		itr++;
		num = num /10 ;
	}
	reverseString(buffer);
}
*/
