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
extern void model_MainClass_stm32f334r8_step(void);
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
	model_MainClass_stm32f334r8_step();
	/* END process execution */
	POST_TASK_DT_MEASURE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF TASK 'Task_5ms'
 ******************************************************************************/
