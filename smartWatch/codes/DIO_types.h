/*
 * DIO_types.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef DIO_DIO_TYPES_H_
#define DIO_DIO_TYPES_H_

#include "DIO_cfg.h"


/*************************************************************************************
 	 	 	 	 	 	 	 	 Module DataTypes
 **************************************************************** ********************/

typedef uint8 Dio_ChannelType ;
typedef uint8 Dio_PortType ;
typedef uint8 Dio_LevelType ;
typedef uint8 Dio_PortLevelType ;


typedef struct{
	Dio_PortType port_number ;
	Dio_ChannelType channel_number ;

}Dio_ConfigChannel;

typedef struct {
	Dio_ConfigChannel Dio_channels[DIO_CONFIGURED_CHANNELS] ;
}Dio_ConfigType;




#endif /* DIO_DIO_TYPES_H_ */
