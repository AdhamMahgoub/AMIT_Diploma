#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <string.h>
#include <util/delay.h>

int main(void)
{
	LCD_voidInit();

	LCD_voidWriteData ('A');
	LCD_set_xy(1,2);

	char key; 
    while(1)
    {
		key = KBD_u8GetPressedKey();
		LCD_voidWriteData (key);
		_delay_ms(100);

    }
}