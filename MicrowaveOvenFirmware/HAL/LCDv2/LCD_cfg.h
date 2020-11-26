/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Pre-Compile Configuration Header file for LCD Module.
 *
 * Author: Sayed Mohsen
 *
 *******************************************************************************/
   
   
#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#include "../../micro_config.h"

/* LCD Mode Configuration */
#define LCD_4BIT_MODE
#define HIGH_NIBBLE

/*Configuration for LCD Data Port */
#define LCD_DATA_PORT PORTC
#define LCD_DATA_DDR  DDRC

/*Configuration for LCD Control Port */
#define LCD_CONTROL_PORT PORTC
#define LCD_CONTROL_DDR DDRC
#define LCD_RS PC0
#define LCD_RW PC1
#define LCD_E PC2

#endif /* HAL_LCD_LCD_CFG_H_ */
