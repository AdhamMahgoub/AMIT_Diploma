#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"    //hwa makatabhash 

/*		Adjusting the global pointer to function		*/
#ifndef 	NULL
#define 	NULL	(void *)0
#endif
/*		This is a Global Pointer to function -- will be used in the main.c file		*/
static void (*EXTI0_CallBack) (void) = NULL; 


void EXTI0_SetCallBack(void(*pf)(void)) 
{
	/*		function to communicate between 2 .c files 				*/
	/*		takes address of function from the main.c w tgebha hena	*/
	/*		hayeb2a gowaha el address bta3 el EXTI0_fun 			*/
	
	EXTI0_CallBack = pf; 
}
void GIE_voidInterruptEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidInterruptDisable(void)
{
	CLR_BIT(SREG,7);
}
void EXTI0_voidInit(void)
{
	/*		EXTI0 => Falling or Rising or both or Low Level		*/
	#if 	SENSE_MODE == EXTI_FALLING
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	#elif 	SENSE_MODE == EXTI_RISING
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	#elif 	SENSE_MODE == EXTI_IOC
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#elif 	SENSE_MODE == EXTI_LOW_LEVEL
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#else 
			#error	"Wrong choice of Sense Mode!"
	#endif 
	
	/*	Disable all interrupts	*/
	CLR_BIT(GICR,6);
	/*	Clear all Flags			*/
	SET_BIT(GIFR,6);
	
}
void EXTI0_voidEnableInterrupt(void)
{
	SET_BIT(GICR,6);

}
void EXTI0_voidDisableInterrupt(void)
{
	CLR_BIT(GICR,6); //hwa katebha set 
}
void __vector_1	(void)
{
	/* 	EXTI0_CallBack() is a global pointer to function	*/
	/*	to execute the EXTI0_fun							*/
	
	/*	pf();			*/
	/*	EXTI0_fun(); 	*/
	
	EXTI0_CallBack();
}

