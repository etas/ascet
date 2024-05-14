/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of ASCTask1ms
 ********************************************************************************/
#include "esdl.h"

/* BEGIN process declarations */
extern void IN_MAIN_EVB_IN_dT(void);
extern void APP_EVB_APP_1ms(void);
extern void OUT_MAIN_EVB_OUT_1ms(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'ASCTask1ms'
 * ----------------------------------------------------------------------------
 * model name:...................................'ASCTask1ms'
 * memory class:.................................'CODE'
 * priority:.....................................'0'
 * period(ms):...................................'1'
 * scheduling:...................................'NONE'
 * ---------------------------------------------------------------------------*/
void ASCTask1ms()
{
	/* BEGIN process execution */
	IN_MAIN_EVB_IN_dT();
	APP_EVB_APP_1ms();
	OUT_MAIN_EVB_OUT_1ms();
	/* END process execution */
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'ASCTask1ms'
 ******************************************************************************/
