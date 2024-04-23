/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of Task_50ms
 ********************************************************************************/
#include "esdl.h"
#include "platform_defs.h"

DEF_GLB_DT_MEASURE;
/* BEGIN process declarations */
extern void classes_VehicleSpeedController_Automatic_calculateVehicleSpeed(void);
extern void classes_Balance2WD_Automatic_calculateFrontDistance(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'Task_50ms'
 * ----------------------------------------------------------------------------
 * model name:...................................'Task_50ms'
 * memory class:.................................'CODE'
 * priority:.....................................'0'
 * period(ms):...................................'50'
 * scheduling:...................................'FULL'
 * ---------------------------------------------------------------------------*/
void Task_50ms()
{
	DEF_TASK_DT_MEASURE;
	PRE_TASK_DT_MEASURE(1.0e-6*50000);
	/* BEGIN process execution */
	classes_VehicleSpeedController_Automatic_calculateVehicleSpeed();
	classes_Balance2WD_Automatic_calculateFrontDistance();
	/* END process execution */
	POST_TASK_DT_MEASURE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'Task_50ms'
 ******************************************************************************/
