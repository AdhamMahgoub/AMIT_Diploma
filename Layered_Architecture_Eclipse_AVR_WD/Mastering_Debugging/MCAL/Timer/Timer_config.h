#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*			Counter or Timer			*/
#define COUNTER 						0
#define TIMER							1

/*			Timer Modes					*/
#define NORMAL							0
#define CTC								1
#define FAST_PWM						2
#define PHASE_CORRECT					3


/*			Timer CLK Select			*/
#define FALLING_EDGE					0
#define RISING_EDGE						1
#define NO_PRESCALER 					2
#define PRESCALER_8						3
#define PRESCALER_64					4
#define PRESCALER_256					5
#define	PRESCALER_1024					6

/*			Compare Output Mode			*/
#define OC0_DISCONNECTED				0
#define TOGGLE_OC0						1
#define CLEAR_OC0						2
#define SET_OC0							3


/*		User POSSILBE OPTIONS		*/
/*		COUNTER_or_TIMER
 * 			COUNTER										// Must Enable ISR function in (TIMER_prog.c) to be able to use it
 * 			TIMER

 * 		TIMER0_MODE
*			NORMAL							
*			CTC								
*			FAST_PWM						
*			PHASE_CORRECT					

 * 		TIMER_CLK_SELECT
 * 			FALLING_EDGE					
 *			RISING_EDGE						
 *			NO_PRESCALER 					
 *			PRESCALER_8						
 *			PRESCALER_64					
 *			PRESCALER_256					
 *			PRESCALER_1024					

 * 		COMPARE_OUTPUT_MODE
 * 			OC0_DISCONNECTED				
 * 			TOGGLE_OC0	(Non-PWM only)		
 * 			CLEAR_OC0						
 * 			SET_OC0							

 */


#define NOT_USED -1 	// NOTE: MUST BE WRITTEN BESIDE THE CONFIGURATIONS THAT ARE NOT USED

/*		User chooses from here		*/
#define COUNTER_or_TIMER						TIMER
#define TIMER_MODE								FAST_PWM
#define TIMER_CLK_SELECT						PRESCALER_1024

/*	Additional Normal Mode Configurations	*/
	#define NORMAL_COMPARE_OUTPUT_MODE			NOT_USED

/*	Additional CTC Mode Configurations		*/
	#define CTC_COMPARE_OUTPUT_MODE				NOT_USED
	#define CTC_OCR0_Value 						NOT_USED				// to control compare match (0 - 255)

/*	Additional FAST_PWM Mode Configuration	*/
	#define FAST_PWM_COMPARE_OUTPUT_MODE		CLEAR_OC0
	#define FAST_PWM_OCR0_Value					255						// to configure duty cycle // Take Care (can't be == 255 -- won't give output -- check graph)

/*	Additional PHASE_CORRECT Configuration	*/
	#define PHASE_CORRECT_COMPARE_OUTPUT_MODE	NOT_USED
	#define PHASE_CORRECT_OCR0_Value			NOT_USED				// to configure duty cycle
/*		End of user configuration	*/










#endif
