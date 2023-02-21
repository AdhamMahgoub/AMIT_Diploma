#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

	 
#include "LCD_interface.h"	 

#include "UART_interface.h"
	 
#include "SPI_interface.h"

#include <avr/interrupt.h>


u8 data; //	Global Variable

		  


int main(void)
{
	
	/*	LCD_Init	*/
	LCD_voidInit();
	
	/*	UART Init		*/
	UART_Init();
			
	/*	SPI Slave Init	*/			
	SPI_initSlave(); 

				
	while(1)
    {	
			SPI_sendByte('a'); 
	}
	
}