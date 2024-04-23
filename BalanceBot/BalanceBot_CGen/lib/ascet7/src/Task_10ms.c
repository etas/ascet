/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of Task_10ms
 ********************************************************************************/
#include "esdl.h"
#include "platform_defs.h"

DEF_GLB_DT_MEASURE;
/* BEGIN process declarations */
extern void classes_TurnSpeedController_Automatic_calculateTurnSpeed(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'Task_10ms'
 * ----------------------------------------------------------------------------
 * model name:...................................'Task_10ms'
 * memory class:.................................'CODE'
 * priority:.....................................'0'
 * period(ms):...................................'10'
 * scheduling:...................................'FULL'
 * ---------------------------------------------------------------------------*/
void Task_10ms()
{
	DEF_TASK_DT_MEASURE;
	PRE_TASK_DT_MEASURE(1.0e-6*10000);
	/* BEGIN process execution */
	classes_TurnSpeedController_Automatic_calculateTurnSpeed();
	/* END process execution */
	POST_TASK_DT_MEASURE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'Task_10ms'
 ******************************************************************************/
