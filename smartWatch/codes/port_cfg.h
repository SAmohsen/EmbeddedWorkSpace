/*
 * port_cfg.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "std_types.h"
#include "port.h"

#define PORT_CONFIGURED_CHANNELS (5U)


/*BUTTON 1 */
#define portConf_INT0_CHANNEL1_ID_INDX 0X00
#define portConf_INT0_CHANNEL1_CHANNEL_NUMBER PIN_26
#define portConf_INT0_CHANNEL1_PORT_NUMBER  PORTD_ID
#define portConf_INT0_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT0_CHANNEL1_INPUT_PIN_MODE	Disable_Pull_up
/*BUTTON 2 */
#define portConf_INT1_CHANNEL1_ID_INDX 0X01
#define portConf_INT1_CHANNEL1_CHANNEL_NUMBER PIN_27
#define portConf_INT1_CHANNEL1_PORT_NUMBER  PORTD_ID
#define portConf_INT1_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT1_CHANNEL1_INPUT_PIN_MODE	Disable_Pull_up
/*BUTTON 3 */
#define portConf_INT2_CHANNEL1_ID_INDX 0X02
#define portConf_INT2_CHANNEL1_CHANNEL_NUMBER PIN_10
#define portConf_INT2_CHANNEL1_PORT_NUMBER  PORTB_ID
#define portConf_INT2_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT2_CHANNEL1_INPUT_PIN_MODE	Disable_Pull_up

/*LM35*/
#define portConf_LM35_CHANNEL_ID_INDX 0X03
#define portConf_LM35_CHANNEL_CHANNEL_NUMBER PIN_0
#define portConf_LM35_CHANNEL_PORT_NUMBER  PORTA_ID
#define portConf_LM35_CHANNEL_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_LM35_CHANNEL_INPUT_PIN_MODE	Disable_Pull_up

/*LED 1 */
#define portConf_LED_CHANNEL_ID_INDX 0X04
#define portConf_LED_CHANNEL_CHANNEL_NUMBER PIN_15
#define portConf_LED_CHANNEL_PORT_NUMBER  PORTB_ID
#define portConf_LED_CHANNEL_CHANNEL_DIRECTION PORT_PIN_OUT
#define portConf_LED_CHANNEL_INPUT_PIN_MODE	initial_Low





#endif /* PORT_CFG_H_ */
