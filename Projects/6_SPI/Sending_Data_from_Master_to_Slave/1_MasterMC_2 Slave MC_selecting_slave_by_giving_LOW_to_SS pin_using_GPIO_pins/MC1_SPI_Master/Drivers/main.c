#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
	 
#define slave1 PIN0
#define slave2 PIN1

int main(void)
{

	/*	SPI Master Init	*/
	SPI_initMaster();


	/*	Select the Slave 1	*/		 
	DIO_voidSetPinValue(PORTD, slave1, LOW);	

	
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
						   