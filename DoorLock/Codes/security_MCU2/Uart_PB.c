 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: Uart_PBcfg.c
 *
 * Description: Post Build Configuration Source file for UART Module.
 *
 * Author: sayed mohsen
 ******************************************************************************/
#include "UART.h"
const Uart_ConfigChannel UartConfigurations={no_parity,Two_Stop_Bits,no_clock,data_8,double_transmission_speed,9600,interrupts,Asynchronous_operation};
