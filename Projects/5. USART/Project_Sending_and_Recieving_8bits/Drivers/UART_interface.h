#ifndef UART_interface_h
#define UART_interface_h

void UART_Init (void);
void UART_SendByte (u8 Byte);
u8 UART_RecieveByte (void);


#endif