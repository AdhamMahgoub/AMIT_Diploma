#ifndef					EXTI_INTERFACE_H
#define 				EXTI_INTERFACE_H

void GIE_voidInterruptEnable(void);
void GIE_voidInterruptDisable(void);

void EXTI0_voidInit(void);
void EXTI0_voidEnableInterrupt(void);
void EXTI0_voidDisableInterrupt(void);
void EXTI0_SetCallBack_ptr2func(void(*pf)(void));
void __vector_1	(void) __attribute__((signal,	used)); //to avoid compiler optimization

void EXTI1_voidInit(void);
void EXTI1_voidEnableInterrupt(void);
void EXTI1_voidDisableInterrupt(void);
void EXTI1_SetCallBack_ptr2func(void(*pf)(void));
void __vector_2	(void) __attribute__((signal,	used)); //to avoid compiler optimization

void EXTI2_voidInit(void);
void EXTI2_voidEnableInterrupt(void);
void EXTI2_voidDisableInterrupt(void);
void EXTI2_SetCallBack_ptr2func(void(*pf)(void));
void __vector_3	(void) __attribute__((signal,	used)); //to avoid compiler optimization


#endif
