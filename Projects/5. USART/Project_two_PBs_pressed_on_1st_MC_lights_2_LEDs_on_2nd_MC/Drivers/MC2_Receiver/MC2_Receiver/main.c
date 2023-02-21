#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"


int main(void)
{
		/*	LCD_Init	*/
		LCD_voidInit();

		/*	UART Init	*/
		UART_Init(); 

		/*	Configure the LED Pins as output		*/
		DIO_voidSetPinDirection(PORTC, PIN0, OUTPUT);
		DIO_voidSetPinDirection(PORTC, PIN1, OUTPUT);
		
		u8 Byte; 
		
				
	while(1)
    {	
		
			Byte = UART_RecieveByte();
			LCD_clear();
			LCD_voidWriteData(Byte);
		

		   /**				PB1 + LED1				**/
		   if (Byte == '0')
			   TOG_BIT(PORTC_REG, PIN0);

		   else if (Byte == '1')
			   TOG_BIT(PORTC_REG, PIN1);

	}
	
	
}