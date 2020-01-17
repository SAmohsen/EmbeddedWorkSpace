/*
 * DIO.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"
#include "common_marcos.h"

#include "DIO_cfg.h"
#include "DIO_types.h"

#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)


/********************************************************************
 * 						Function ProtoTypes
 * ******************************************************************/
void Dio_Init(const Dio_ConfigType *ConfigPtr) ;



void Dio_WriteChannel(Dio_ChannelType ChannelId,
					  Dio_LevelType Level) ;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) ;


#endif /* DIO_H_ */
