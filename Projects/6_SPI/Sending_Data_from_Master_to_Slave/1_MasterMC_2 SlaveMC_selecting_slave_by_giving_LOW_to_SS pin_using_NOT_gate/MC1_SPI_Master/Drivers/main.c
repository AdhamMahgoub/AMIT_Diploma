#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"


int main(void)
{

	/*	SPI Master Init	*/
	SPI_initMaster();

	
	while(1)
	{
		if(DIO_u8GetPinValue(PORTA, PIN0) == 0)//button pressed
		{
			SPI_sendByte('1');
			while(DIO_u8GetPinValue(PORTA, PIN0) == 0);		//Wait until Unpressed
			
		}
		else if(DIO_u8GetPinValue(PORTA, PIN0) == 1)//button unpressed
		{
			SPI_sendByte('0');
			while(DIO_u8GetPinValue(PORTA, PIN0) == 1);	  //Wait until Pressed
		}
	}
	
}
						   