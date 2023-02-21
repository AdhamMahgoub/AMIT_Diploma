#ifndef			LCD_INTERFACE_H
#DEFINE 		LCD_INTERFACE_H



#define 		LCD_DATA_PORT			PORTA
#define			LCD_CONTROL_PORT		PORTB

#DEFINE			LCD_RS					PIN0
#DEFINE			LCD_RW					PIN1
#DEFINE			LCD_EN					PIN2


void LCD_voidInit(void);
void LCD_voidSendCMD(u8 CMD);
void LCD_voidWriteData(u8 Data);



/*example

LCD_voidInit(void);
LCD_voidSendCMD(CMD);
LCD_voidWriteData(DATA);

*/