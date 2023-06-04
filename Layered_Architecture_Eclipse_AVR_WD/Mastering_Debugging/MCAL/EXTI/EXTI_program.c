#include "../../LIB/STD_TYPES.H"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"  


void GIE_voidInterruptEnable(void)
{
	// Global Interrupt Enable
	SET_BIT(SREG,7);
}

void GIE_voidInterruptDisable(void)
{
	CLR_BIT(SREG,7);
}

/*		#####		EXTI0		#####		*/
/*		Global Pointer to Function (EXTI0_CallBack)		*/
#ifndef 	NULL
#define 	NULL	(void *)0
#endif
static void (*EXTI0_CallBack_ptr2func) (void) = NULL;

void EXTI0_voidEnableInterrupt(void)
{
	SET_BIT(GICR,6);
}

void EXTI0_voidDisableInterrupt(void)
{
	CLR_BIT(GICR,6);
}

void EXTI0_voidInit(void)
{
	/*		EXTI0 => Falling or Rising or both or Low Level		*/
#if 	EXTI0_SENSE_MODE == EXTI0_FALLING
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif 	EXTI0_SENSE_MODE == EXTI0_RISING
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif 	EXTI0_SENSE_MODE == EXTI0_IOC
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif 	EXTI0_SENSE_MODE == EXTI0_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#else
#error	"Wrong choice of Sense Mode!"
#endif

	//CLR_BIT(GICR,6);	/*	Disable interrupt 0	-- Optional		*/
	//SET_BIT(GIFR,6);	/*	Clear INT0 flag (INTF0)	-- Optional */
}

void EXTI0_SetCallBack_ptr2func(void(*pf)(void))
{
	/*		pf is a pointer to function 					*/
	/*		pf points to function EXTI0_fun "in main.c" 	*/
	EXTI0_CallBack_ptr2func = pf;
}

void __vector_1	(void)
{
	/*	This is ISR	Function	*/
	EXTI0_CallBack_ptr2func();
}



/*		#####		EXTI1		#####		*/
/*		Global Pointer to Function (EXTI0_CallBack)		*/
static void (*EXTI1_CallBack_ptr2func) (void) = NULL;

void EXTI1_voidEnableInterrupt(void)
{
	SET_BIT(GICR,7);
}

void EXTI1_voidDisableInterrupt(void)
{
	CLR_BIT(GICR,7);
}

void EXTI1_voidInit(void)
{
	/*		EXTI1 => Falling or Rising or both or Low Level		*/
#if 	EXTI1_SENSE_MODE == EXTI1_FALLING
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif 	EXTI1_SENSE_MODE == EXTI1_RISING
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif 	EXTI1_SENSE_MODE == EXTI1_IOC
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif 	EXTI1_SENSE_MODE == EXTI1_LOW_LEVEL
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#else
#error	"Wrong choice of Sense Mode!"
#endif


	//CLR_BIT(GICR,7);	/*	Disable interrupt 0	-- Optional		*/
	//SET_BIT(GIFR,7);	/*	Clear INT1 flag (INTF1)	-- Optional */
}

void EXTI1_SetCallBack_ptr2func(void(*pf)(void))
{
	/*		pf is a pointer to function 					*/
	/*		pf points to function EXTI0_fun "in main.c" 	*/
	EXTI1_CallBack_ptr2func = pf;
}

void __vector_2	(void)
{
	/*	This is ISR	Function	*/
	EXTI1_CallBack_ptr2func();
}

