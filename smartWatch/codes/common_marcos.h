/*
 ============================================================================
 Name        : common_macros.h
 Author      : sayed mohsen
 Description : Header file for the commonly used Macros
 Date        : 19/12/2019
 ============================================================================
 */

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/*set  low nipple in any register */
#define SET_LOW_NIBBLE(REG)  ( REG=(REG|0x0F) )

/*set  high nipple in any register */
#define SET_HIGH_NIBBLE(REG)  (REG = (REG|0xF0) )

/****************************************************/

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/*clear  low nipple in any register */
#define CLR_LOW_NIBBLE(REG)  ( REG=(REG&0xF0) )

/*clear  high nipple in any register */
#define CLR_HIGH_NIBBLE(REG)  ( REG=(REG&0x0F) )

/****************************************************/

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/*toggle  low nipple in any register */
#define TOGGLE_LOW_NIBBLE(REG)  ( REG=(REG^0x0F) )

/*toggle  high nipple in any register */
#define TOGGLE_HIGH_NIBBLE(REG)  ( REG=(REG^0xF0) )

/********************************************************/

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

/*********************************************************/
/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/********************************************************/
/* read a certain bit in any register */
#define READ_BIT(REG,BIT) ((REG>>BIT) & 0X01)

/*read  low nipple in any register */
#define READ_LOW_NIBBLE (REG) (REG&0x0F)

/*read  high nipple in any register */
#define READ_HIGH_NIBBLE (REG) ((REG&0xF0)>>4)

/*read value of  any group of contiguous pins at any register*/
#define READ_GROUP(REG,MASK,OFFSET) ((REG&MASK)>>OFFSET)

/**********************************************************/

/*write value on  low nipple in any register*/
#define WRITE_LOW_NIBBLE(REG,VALUE) (REG=((REG&0xF0)|(VALUE&0x0F))
/*write value on  high nipple in any register*/
#define WRITE_HIGH_NIBBLE(REG,VALUE) (REG=(REG&0x0F)|((VALUE&0x0F)<<4))
/*write value on  any group of contiguous pins at any register*/
#define WRITE_GROUP(REG,VALUE,MASK,OFFSET) (REG=(REG &(~MASK))|(VALUE<<OFFSET))

#endif

