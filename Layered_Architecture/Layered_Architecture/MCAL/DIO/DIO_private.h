#ifndef			DIO_PRIVATE_H
#define 		DIO_PRIVATE_H

/*	Notes: 

	DDR: 	Control direction of pins (input or output)
	PORT: 	OUTPUT
	PIN: 	INPUT
*/


#define PORTA_REG_Address	0x3B
#define DDRA_REG_Address	0x3A
#define PINA_REG_Address	0x39

#define PORTB_REG_Address	0x38
#define DDRB_REG_Address	0x37
#define PINB_REG_Address	0x36

#define PORTC_REG_Address	0x35
#define DDRC_REG_Address	0x34
#define PINC_REG_Address	0x33

#define PORTD_REG_Address	0x32
#define DDRD_REG_Address	0x31
#define PIND_REG_Address	0x30



/*				PORTA REGISTERS				*/
#define 		PORTA_REG		*((volatile u8 *)PORTA_REG_Address)
#define 		DDRA_REG		*((volatile u8 *)DDRA_REG_Address) 
#define 		PINA_REG		*((volatile u8 *)PINA_REG_Address) 

/*				PORTB REGISTERS				*/
#define 		PORTB_REG		*((volatile u8 *)PORTB_REG_Address)
#define 		DDRB_REG		*((volatile u8 *)DDRB_REG_Address)
#define 		PINB_REG		*((volatile u8 *)PINB_REG_Address)

/*				PORTC REGISTERS				*/
#define 		PORTC_REG		*((volatile u8 *)PORTC_REG_Address)
#define 		DDRC_REG		*((volatile u8 *)DDRC_REG_Address)
#define 		PINC_REG		*((volatile u8 *)PINC_REG_Address)

/*				PORTD REGISTERS				*/
#define 		PORTD_REG		*((volatile u8 *)PORTD_REG_Address)
#define 		DDRD_REG		*((volatile u8 *)DDRD_REG_Address)
#define 		PIND_REG		*((volatile u8 *)PIND_REG_Address)


#endif