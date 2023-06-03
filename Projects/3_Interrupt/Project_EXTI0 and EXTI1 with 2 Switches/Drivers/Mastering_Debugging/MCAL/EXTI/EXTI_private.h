#ifndef				EXTI_PRIVATE_H
#define 			EXTI_PRIVATE_H
	
#define 			SREG				*((volatile u8 *)0x5F)  
#define 			GICR				*((volatile u8 *)0x5B)
#define 			GIFR				*((volatile u8 *)0x5A)
#define 			MCUCR				*((volatile u8 *)0x55)
#define 			MCUCSR				*((volatile u8 *)0x54)

#endif
