#ifndef			DIO_PRIVATE_H
#define 		DIO_PRIVATE_H

/*explanation
	DDR: 	direction 
	PORT: 	OUTPUT
	PIN: 	INPUT
*/


/*				PORTA REGISTERS				*/
#define 		PORTA_REG		*((volatile u8 *)0x3B) //output
#define 		DDRA_REG		*((volatile u8 *)0x3A) //DIRECTION
#define 		PINA_REG		*((volatile u8 *)0x39) //input

/*				PORTB REGISTERS				*/
#define 		PORTB_REG		*((volatile u8 *)0x38)
#define 		DDRB_REG		*((volatile u8 *)0x37)
#define 		PINB_REG		*((volatile u8 *)0x36)

/*				PORTC REGISTERS				*/
#define 		PORTC_REG		*((volatile u8 *)0x35)
#define 		DDRC_REG		*((volatile u8 *)0x34)
#define 		PINC_REG		*((volatile u8 *)0x33)

/*				PORTD REGISTERS				*/
#define 		PORTD_REG		*((volatile u8 *)0x32)
#define 		DDRD_REG		*((volatile u8 *)0x31)
#define 		PIND_REG		*((volatile u8 *)0x30)


#endif