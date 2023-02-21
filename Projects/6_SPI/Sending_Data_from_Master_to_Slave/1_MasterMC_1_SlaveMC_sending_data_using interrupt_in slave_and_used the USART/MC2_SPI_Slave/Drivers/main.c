#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"
	 
#include "LCD_interface.h"	 
	 
#include "SPI_interface.h"
#include "SPI_private.h"

#include <avr/interrupt.h>


u8 data; //	Global Variable

ISR(SPI_STC_vect)
{
	//Receive Data		
	data = SPDR;
	LCD_voidWriteData(data);
}		  


int main(void)
{
	
	/*	LCD_Init	*/
	LCD_voidInit();
			
	/*	SPI Slave Init	*/			
	SPI_initSlave(); 

				
	while(1)
    {
			//
	}
	
}