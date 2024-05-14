/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of StartupHook
 ********************************************************************************/

/* BEGIN process declarations */
extern void IN_MAIN_EVB_IN_Init(void);
extern void OUT_MAIN_EVB_OUT_Init(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'StartupHook'
 * ----------------------------------------------------------------------------
 * model name:...................................'StartupHook'
 * memory class:.................................'CODE'
 * priority:.....................................'-'
 * period(ms):...................................'-'
 * scheduling:...................................'-'
 * ---------------------------------------------------------------------------*/
void esdl_StartupHook()
{
	/* BEGIN process execution */
	IN_MAIN_EVB_IN_Init();
	OUT_MAIN_EVB_OUT_Init();
	/* END process execution */
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'StartupHook'
 ******************************************************************************/
