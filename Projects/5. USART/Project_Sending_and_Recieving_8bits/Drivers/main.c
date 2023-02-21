#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"


int main(void)
{
		u8 Byte;
	
		UART_Init();						//	UART Init

	

    while(1)
    {
        Byte = UART_RecieveByte();
        UART_SendByte(Byte);	
    }
}