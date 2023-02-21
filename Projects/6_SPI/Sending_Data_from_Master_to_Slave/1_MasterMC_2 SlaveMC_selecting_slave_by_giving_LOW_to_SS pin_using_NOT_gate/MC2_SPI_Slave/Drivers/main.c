#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"
	 
#include "LCD_interface.h"	 
	 
#include "SPI_interface.h"


int main(void)
{

	/*	LED	Init	*/
	DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
	
	/*	LCD_Init	*/
	LCD_voidInit();
			
	/*	SPI Slave Init	*/			
	SPI_initSlave(); 

	/*	Receive Data	*/
	u8 data;
	
				
	while(1)
    {
		data = SPI_recieveByte();
		if(data == '1')
		{
			DIO_voidSetPinValue(PORTC, PIN0, HIGH);	  
			LCD_voidWriteData(data);
		}
		else if(data == '0')
		{
			DIO_voidSetPinValue(PORTC, PIN0, LOW);	
			LCD_voidWriteData(data);
		}
	}
	
}