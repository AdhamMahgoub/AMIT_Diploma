#ifndef			UART_PRIVATE_H
#define 		UART_PRIVATE_H


#define 		UDR				*((volatile u8 *)0x2C)
#define 		UCSRA			*((volatile u8 *)0x2B)
#define 		UCSRB			*((volatile u8 *)0x2A)
#define 		UCSRC			*((volatile u8 *)0x40)		 //they both have the same address
#define 		UBRRH			*((volatile u8 *)0x40)		 //they both have the same address
#define 		UBRRL			*((volatile u8 *)0x29)
			 
				 
/*			UCSRB Register		*/
#define RXEN_bit	3	//Transmitter Enable 
#define TXEN_bit	4	//Receiver Enable 	
				
/*			UCSRC Register		*/
#define UCSZ0_bit	1
#define UCSZ1_bit  	2
#define USBS_bit	3	   
#define UPM0_bit	4
#define UPM1_bit 	5
#define UMSEL_bit	6
#define URSEL_bit	7

/*			UCSRA Register		*/
#define UDRE_bit	5
#define RXC_bit		7
				  	 
#endif