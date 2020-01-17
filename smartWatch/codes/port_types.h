/*
 * port_types.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#include "std_types.h"
#include "port_cfg.h"

/*************************************************************************************
 	 	 	 	 	 	 	 	 Module DataTypes
 **************************************************************** ********************/

typedef uint8 Port_PinType ;
typedef uint8 Port_PortType;


typedef enum  {PORT_PIN_IN ,
			   PORT_PIN_OUT
			  }Port_PinDirectionType;


typedef enum{
	Disable_Pull_up,
	Enable_Pull_up
}Port_Input_Mode;

typedef enum{
	initial_Low,
	initial_High
}Port_output_Mode;


typedef struct
{
	Port_PortType port ;
	Port_PinType pin_num;
	Port_PinDirectionType direction;
	Port_Input_Mode pin_in_mode ;
	Port_output_Mode pin_out_mode ;
}Port_ConfigChannel;

typedef struct {
	Port_ConfigChannel port_channels[PORT_CONFIGURED_CHANNELS];
}Port_ConfigType;
