#include "main.h"

int main(int argc, char **argv) {
	/*Data To Be Sent*/
	uint8 *mydata="AABBCCDD#";
	uint8 rcv_Byte;

	/*Initialize UART Driver */
	Uart_init(&UartConfigurations);

	/*Request To Transmit New DaTa */
	Uart_SendU8Data(REQUEST_TO_SEND);

	/*Wait Until DCE Is Ready*/
	while(CLEAR_TO_SEND!=rcv_Byte)
	{
		rcv_Byte = Uart_RecieveU8Data();
	}

	/*Transmit New Data */
	Uart_SendString(mydata);
	while (1) ;
}
