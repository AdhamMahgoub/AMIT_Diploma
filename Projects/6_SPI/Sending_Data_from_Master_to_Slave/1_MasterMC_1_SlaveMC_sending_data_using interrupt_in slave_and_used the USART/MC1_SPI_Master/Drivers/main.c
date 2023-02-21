#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "UART_interface.h"

#include "SPI_interface.h"
	 


int main(void)
{
	/*	UART Init		*/
	UART_Init();
	u8 data; 

	/*	SPI Master Init	*/
	SPI_initMaster();


	while(1)
	{
		  data = UART_RecieveByte();
		  SPI_sendByte(data);
	}
	
	
}
						   