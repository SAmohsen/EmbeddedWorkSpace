/*
 * common_marcos.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef COMMON_MARCOS_H_
#define COMMON_MARCOS_H_


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT) (REG&= (~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define READ_BIT(REG,BIT) ((REG>>BIT) & 0X01)
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

#endif /* COMMON_MARCOS_H_ */
