 /******************************************************************************
 *
 * Module: calculator
 *
 * File Name: Calculator.c
 *
 * Description: Source file for basic Calculator
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/


#include "calculator.h"

sint32 calculate(char *firstoperand, uint8 firstoperandlength,char *secondoperand, uint8 secondoperandlength, char operation) ;
uint32 strToInteger(char *str, uint8 length) ;
sint32 makearithmaticoperation(uint32 num1, uint32 num2, char operation) ;

uint8 error_status = 0 ;

int main(void) {
	char firstoperand[16] ;/*string to hold value of first number*/
	char secondoperand[16] ;/*string to hold value of second number*/
	uint8 firstoperandlength = 0;/*iterator on first number*/
	uint8 secondoperandlength = 0;/*iterator on second number*/
	uint8 secondoperandFlag = 0;/*flag indicates to start of first number*/
	char operation;/*Arithmetic operation between two numbers*/
	char key;/*keypad pressed key*/
	sint32 result;/*variable to hold result of arithmetic operation*/
	uint8 resultonscreen = 0 ;/*flag indicates result on screen */
	LCD_Init(); /* initialize LCD */
	LCD_Clear(); /* clear the LCD display */
	LCD_goToXY(1, 0);/*display first operand*/

	while (1) {
		key = Keypad_getPressedKey();
		if ((key >= 48) && (key <= 57)&&!resultonscreen)
		{
			key = key - 48; /* convert ASCIIto integer*/
			LCD_sendu32Data(key);
			if (!secondoperandFlag)
			{
				firstoperand[firstoperandlength] = key;
				firstoperandlength++;
			}
			else
			{
				secondoperand[secondoperandlength] = key;
				secondoperandlength++;
			}
		}
		else if (key == '=') {
			firstoperand[firstoperandlength] = '\0'; /*terminate first operand */
			secondoperand[secondoperandlength] = '\0'; /*terminate second operand */
			result = calculate(firstoperand, firstoperandlength, secondoperand,secondoperandlength, operation);
			if (error_status == 1) {
				LCD_Clear();
				LCD_SendString("Syntax Error ! ");
			} else {
				LCD_goToXY(4, 0);
				if (result < 0) {
					result = result * -1U;
					LCD_SendU8Data('-');/*Display negative sign*/
				}
				LCD_sendu32Data(result);/*Display result*/
			}
			resultonscreen = 1;

		}
		else if (key == ' ') {
			/*clear operands and flags */
			LCD_Clear();
			firstoperandlength = 0;
			secondoperandlength = 0;
			secondoperandFlag = 0;
			resultonscreen = 0;
			error_status = 0;
		}
		else if(!resultonscreen) {
			operation = key;
			LCD_goToXY(2, 0);/*display first operand*/
			LCD_SendU8Data(operation);/*display operation*/
			secondoperandFlag = 1;/*flag indicates to second number*/
			LCD_goToXY(3, 0);/*display second operand*/

		}
		else{

		}

	}/*end while loop*/

}
sint32 calculate(char *firstoperand, uint8 firstoperandlength,char *secondoperand, uint8 secondoperandlength, char operation) {
	uint32 num1 = strToInteger(firstoperand, firstoperandlength);/*get first number*/
	uint32 num2 = strToInteger(secondoperand, secondoperandlength);/*get second number*/
	return makearithmaticoperation(num1,num2,operation);/*calculate desired operation*/

}


uint32 strToInteger(char *str, uint8 length) {
	uint32 num = 0;
	uint32 multiplier = 1;
	uint8 i = 0;
	for (i = 1; i < length; i++) {
		multiplier = multiplier * 10;
	}
	i = 0;
	while (str[i] != '\0') {
		num = num + ((str[i]) * multiplier);
		multiplier = multiplier / 10;
		i++;
	}
	return num;
}
sint32 makearithmaticoperation(uint32 num1, uint32 num2, char operation) {
	sint32 result =0;
	switch (operation) {
	case '*':result = num1 * num2;
	break;
	case '/':
		if (num2 == 0) {
			error_status = 1;/*divide by zero error */
		} else {
			result = num1 / num2;
		}
	break;
	case '+':result = num1 + num2;
	break;
	case '-':result = num1 - num2;
	break;
	}
	return result;
}
