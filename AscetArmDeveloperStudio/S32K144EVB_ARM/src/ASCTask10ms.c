/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of ASCTask10ms
 ********************************************************************************/
#include "esdl.h"

/* BEGIN process declarations */
extern void APP_EVB_APP_10ms(void);
extern void OUT_MAIN_EVB_OUT_10ms(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'ASCTask10ms'
 * ----------------------------------------------------------------------------
 * model name:...................................'ASCTask10ms'
 * memory class:.................................'CODE'
 * priority:.....................................'2'
 * period(ms):...................................'10'
 * scheduling:...................................'NONE'
 * ---------------------------------------------------------------------------*/
void ASCTask10ms()
{
	/* BEGIN process execution */
	APP_EVB_APP_10ms();
	OUT_MAIN_EVB_OUT_10ms();
	/* END process execution */
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'ASCTask10ms'
 ******************************************************************************/
