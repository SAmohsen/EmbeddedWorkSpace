 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../std_types.h"
#include "../../common_marcos.h"

#include ".../../LCD_cfg.h"



/* LCD Commands MT */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_DISPLAY_RIGHT 0x1C

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
typedef uint8 Lcd_DataType ;
typedef uint8 Lcd_CommandType ;
/*******************************************************************************
 *                              Function ProtoTypes                              *
 *******************************************************************************/
void LCD_Init();
void LCD_SendCommand(Lcd_CommandType command);
void LCD_SendU8Data(Lcd_DataType data);
void LCD_SendString(char * str);
void LCD_Clear(void);
void LCD_goToXY(uint8 x, uint8 y);
void LCD_SendIntegerData(int data);
void LCD_SendU32Data(int data) ;
#endif /* HAL_LCD_LCD_H_ */
