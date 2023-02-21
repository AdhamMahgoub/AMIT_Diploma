#define F_CPU	16000000UL		//	16 MHz	  /*		MUST be before the delay library		*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "UART_interface.h"


int main(void)
{
		u8 Byte;
	
		/*	LCD Init	*/
		LCD_voidInit();
		LCD_print_string("LCD Ready");
		/*	UART Init	*/
		UART_Init(); 

   
    while(1)
    {
        Byte = UART_RecieveByte();
        LCD_clear();
        LCD_voidWriteData(Byte);
    }
	
	
}