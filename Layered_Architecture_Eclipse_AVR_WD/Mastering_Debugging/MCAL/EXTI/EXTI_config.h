#ifndef				EXTI_CONFIG_H
#define				EXTI_CONFIG_H


/********************************************************************************************/
/**			Sense Mode can be : 															*/
/**								1-	EXTI_FALLING											*/
/*								2-	EXTI_RISING												*/
/*                              3-	EXTI_IOC                                                */
/*                              4-	EXTI_LOW_LEVEL                                          */
/********************************************************************************************/

/*		EXTI0			*/
#define EXTI0_Falling 	0
#define EXTI0_RISING 	1
#define EXTI0_IOC		2
#define EXTI0_LOW_LEVEL	3

#define EXTI0_SENSE_MODE		EXTI_Falling

/*		EXTI1			*/
#define EXTI1_Falling 	0
#define EXTI1_RISING 	1
#define EXTI1_IOC		2
#define EXTI1_LOW_LEVEL	3

#define EXTI1_SENSE_MODE		EXTI_Falling


/*		EXTI2			*/
#define EXTI2_Falling 	0
#define EXTI2_RISING 	1
#define EXTI2_IOC		2
#define EXTI2_LOW_LEVEL	3

#define EXTI2_SENSE_MODE		EXTI_Falling


#endif
