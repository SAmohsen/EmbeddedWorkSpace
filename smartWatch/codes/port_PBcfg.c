/*
 * port_PBcfg.c
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#include "std_types.h"
#include "port.h"
#include "port_cfg.h"

const Port_ConfigType port_configuration =
{
  .port_channels[portConf_INT0_CHANNEL1_ID_INDX].pin_num = portConf_INT0_CHANNEL1_CHANNEL_NUMBER ,
  .port_channels[portConf_INT0_CHANNEL1_ID_INDX].port = portConf_INT0_CHANNEL1_PORT_NUMBER,
  .port_channels[portConf_INT0_CHANNEL1_ID_INDX].direction = portConf_INT0_CHANNEL1_CHANNEL_DIRECTION,
  .port_channels[portConf_INT0_CHANNEL1_ID_INDX].pin_out_mode = portConf_INT0_CHANNEL1_INPUT_PIN_MODE,

  .port_channels[portConf_INT1_CHANNEL1_ID_INDX].pin_num = portConf_INT1_CHANNEL1_CHANNEL_NUMBER ,
  .port_channels[portConf_INT1_CHANNEL1_ID_INDX].port = portConf_INT1_CHANNEL1_PORT_NUMBER,
  .port_channels[portConf_INT1_CHANNEL1_ID_INDX].direction = portConf_INT1_CHANNEL1_CHANNEL_DIRECTION,
  .port_channels[portConf_INT1_CHANNEL1_ID_INDX].pin_out_mode = portConf_INT1_CHANNEL1_INPUT_PIN_MODE,

  .port_channels[portConf_INT2_CHANNEL1_ID_INDX].pin_num = portConf_INT2_CHANNEL1_CHANNEL_NUMBER ,
  .port_channels[portConf_INT2_CHANNEL1_ID_INDX].port = portConf_INT2_CHANNEL1_PORT_NUMBER,
  .port_channels[portConf_INT2_CHANNEL1_ID_INDX].direction = portConf_INT2_CHANNEL1_CHANNEL_DIRECTION,
  .port_channels[portConf_INT2_CHANNEL1_ID_INDX].pin_out_mode = portConf_INT2_CHANNEL1_INPUT_PIN_MODE,

  .port_channels[portConf_LM35_CHANNEL_ID_INDX].pin_num = portConf_LM35_CHANNEL_CHANNEL_NUMBER ,
  .port_channels[portConf_LM35_CHANNEL_ID_INDX].port = portConf_LM35_CHANNEL_PORT_NUMBER,
  .port_channels[portConf_LM35_CHANNEL_ID_INDX].direction = portConf_LM35_CHANNEL_CHANNEL_DIRECTION,
  .port_channels[portConf_LM35_CHANNEL_ID_INDX].pin_out_mode = portConf_LM35_CHANNEL_INPUT_PIN_MODE,

  .port_channels[portConf_LED_CHANNEL_ID_INDX].pin_num = portConf_LED_CHANNEL_CHANNEL_NUMBER ,
  .port_channels[portConf_LED_CHANNEL_ID_INDX].port = portConf_LED_CHANNEL_PORT_NUMBER,
  .port_channels[portConf_LED_CHANNEL_ID_INDX].direction = portConf_LED_CHANNEL_CHANNEL_DIRECTION,
  .port_channels[portConf_LED_CHANNEL_ID_INDX].pin_out_mode = portConf_LED_CHANNEL_INPUT_PIN_MODE,

};

