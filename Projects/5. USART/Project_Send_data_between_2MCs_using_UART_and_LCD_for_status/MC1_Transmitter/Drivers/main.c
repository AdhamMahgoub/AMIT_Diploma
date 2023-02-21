#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"



int main(void)
{

		/*	UART Init	*/
		UART_Init(); 
		
		
		/*	Activate Pull up Resistor for switches	*/
		DIO_voidSetPinDirection(PORTA, PIN0, INPUT);
		//DIO_voidSetPinDirection(PORTA, PIN1, INPUT);
		
		DIO_voidSetPinValue(PORTA, PIN0, HIGH);
		//DIO_voidSetPinValue(PORTA, PIN1, HIGH);

		DIO_voidSetPinValue(PORTC, PIN0, HIGH);
		//DIO_voidSetPinValue(PORTA, PIN1, HIGH);
		
		
		
   
    while(1)
    {	
			/*				PB1 + LED1				*/
			if ((DIO_u8GetPinValue(PORTA,PIN0)) == 1)			//Not Pressed
			{
				UART_SendByte('1');
				while (DIO_u8GetPinValue(PORTA,PIN0) == 1)
				{
						  //to wait till pressed  (send data once) 
				}		
			}
				
			
			if ((DIO_u8GetPinValue(PORTA,PIN0)) == 0)		//Pressed
			{
				UART_SendByte('0');
				while (DIO_u8GetPinValue(PORTA,PIN0) == 0)		
				{
					   //Wait till unpressed	 (send data once) 
				}		
			}

	}
	
}


