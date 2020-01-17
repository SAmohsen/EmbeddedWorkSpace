/*
 * DIO_PBcfg.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */


#include "DIO.h"
#include "DIO_cfg.h"


/*post build configurations */
const Dio_ConfigType DIO_configuration = {
		.Dio_channels[DioConf_LED_PORT_ID_INDEX].channel_number=DioConf_LED_channel_NUMBER,
		.Dio_channels[DioConf_LED_PORT_ID_INDEX].port_number=DioConf_LED_PORT_NUMBER,

};
