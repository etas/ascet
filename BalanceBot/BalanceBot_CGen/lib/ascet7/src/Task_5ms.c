/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   implementation of Task_5ms
 ********************************************************************************/
#include "esdl.h"
#include "platform_defs.h"

DEF_GLB_DT_MEASURE;
/* BEGIN process declarations */
extern void control_RemoteCommandsMain_Automatic_calc(void);
extern void classes_Balance2WD_Automatic_calculatePulseCount(void);
extern void classes_AngleSpeedController_Automatic_calculateInclinationAngle(void);
extern void classes_AngleSpeedController_Automatic_calculateAngleSpeed(void);
extern void classes_Balance2WD_Automatic_calculateMotorPower(void);
/* END process declarations */

/******************************************************************************
 * BEGIN: DEFINITION OF TASK 'Task_5ms'
 * ----------------------------------------------------------------------------
 * model name:...................................'Task_5ms'
 * memory class:.................................'CODE'
 * priority:.....................................'0'
 * period(ms):...................................'5'
 * scheduling:...................................'FULL'
 * ---------------------------------------------------------------------------*/
void Task_5ms()
{
	DEF_TASK_DT_MEASURE;
	PRE_TASK_DT_MEASURE(1.0e-6*5000);
	/* BEGIN process execution */
	control_RemoteCommandsMain_Automatic_calc();
	classes_Balance2WD_Automatic_calculatePulseCount();
	classes_AngleSpeedController_Automatic_calculateInclinationAngle();
	classes_AngleSpeedController_Automatic_calculateAngleSpeed();
	classes_Balance2WD_Automatic_calculateMotorPower();
	/* END process execution */
	POST_TASK_DT_MEASURE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'Task_5ms'
 ******************************************************************************/
