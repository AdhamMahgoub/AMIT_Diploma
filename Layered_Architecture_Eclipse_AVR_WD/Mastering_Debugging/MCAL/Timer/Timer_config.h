#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

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




/*		POSSILBE OPTIONS		*/
/*		TIMER0_MODE
*			NORMAL							0
*			CTC								1
*			FAST_PWM						2
*			PHASE_CORRECT					3

 * 		TIMER_CLK_SELECT
 * 			falling_edge					0
 *			rising_edge						1
 *			no_prescalar 					2
 *			prescalar_8						3
 *			prescalar_64					4
 *			prescalar_256					5
 *			prescalar_1024					6

 * 		COMPARE_OUTPUT_MODE
 * 			OC0_DISCONNECTED				0
 * 			TOGGLE_OC0						1
 * 			CLEAR_OC0						2
 * 			SET_OC0							3

 */


/*		User chooses from here		*/
#define TIMER_MODE						NORMAL
#define TIMER_CLK_SELECT				PRESCALER_256
#define COMPARE_OUTPUT_MODE				OC0_DISCONNECTED
#define Duty_cycle						0.25
/*		End of user configuration	*/










#endif
