#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "keypad_interface.h"

#include <util/delay.h>


static u8 KBD[4][4] = {
							{'1', '2', '3', '+'},
							{'4', '5', '6', '-'},
							{'7', '8', '9', '*'},
							{'=', '0', '.', '/'},
						
						};


u8 KBD_u8GetPressedKey (void)
{
	u8 local_u8Key = 0xFF; 
	DIO_voidSetPortDirection(KBD_PORT, 0xF0); 	//1111 0000  (output -- input) 
	DIO_voidSetPortValue(KBD_PORT, 0xF0); 		//0000 1111  (to send high -- deactivate pull up resistor) 
	
	
	for (u8 COL=0; COL<4; COL++)
	{
		DIO_voidSetPinValue(KBD_PORT, COL, LOW); 
		_delay_ms(1000);

		
		for (u8 ROW = 4; ROW < 8; ROW++)
		{
			if(DIO_u8GetPinValue(KBD_PORT, ROW) == 1)
			{
				local_u8Key = KBD[COL][ROW - 4]; 
				_delay_ms(10);
			}
		}
				_delay_ms(1000);

		
		DIO_voidSetPinValue(KBD_PORT, COL, HIGH);	
		_delay_ms(1000);
	}
	
	return local_u8Key;
}		