#include "STD_TYPES.H"
#include "BIT_MATH.h"

#include "DIO_interface.h"
//need to include delay 

void LCD_voidInit(void)
{ 
	
}
void LCD_voidSendCMD(u8 CMD)
{
	/*- Conditions to send cmd 
    1. RS 	= 0 
    2. RW 	= 0
    3. EN 	= pulse 
    4. DATA =  CMD
	*/
	
	/*		1- RS = 0		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS, LOW);
	
	/*		2- RW = 0		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW, LOW);	
	
	/*		3- EN pulse		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, HIGH);

	
	/*		4- SEND CMD		*/
	DIO_voidSetPortValue(LCD_DATA, CMD);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, LOW); //WARNING: he wrote this as HIGH (idk why)
	_delay_ms(5);										
}

void LCD_voidWriteData(u8 Data)
{
	/*- Conditions to send cmd 
    1. RS 	= 1 
    2. RW 	= 0
    3. EN 	= pulse 
    4. DATA =  CMD
	*/
	
	/*		1- RS = 1		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS, HIGH);
	
	/*		2- RW = 0		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW, LOW);	
	
	/*		3- EN pulse		*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, HIGH);

	
	/*		4- SEND CMD		*/
	DIO_voidSetPortValue(LCD_DATA, Data);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN, LOW); //WARNING: he wrote this as HIGH (idk why)
	_delay_ms(5);										
}