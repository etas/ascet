/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................control.RemoteCommandsMain
 * REPRESENTATION:..............Automatic
 * DESCRIPTION:
 *    
 ******************************************************************************/


/*-----------------------------------------------------------------------------
 *    Defines
 *----------------------------------------------------------------------------*/

#define __ASD_REQUIRES_OS_INFACE

/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "control_RemoteCommandsMain_Automatic.h"
#include "interfaces_IRemoteCommands_Automatic.h"


/******************************************************************************
 * DEFINITION OF COMPONENT VARIABLE OMITTED
 * ----------------------------------------------------------------------------
 * memory class:.................................'ROM'
 * model name:...................................'control_RemoteCommandsMain'
 * reason:.......................................no local elements
 * ---------------------------------------------------------------------------*/







/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF PROCESS 'control_RemoteCommandsMain_Automatic_calc'
 * ----------------------------------------------------------------------------
 * model name:...................................'calc'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define CountLeft__control_RemoteCommandsMain_Automatic_calc (CountLeft)
#define CountRight__control_RemoteCommandsMain_Automatic_calc (CountRight)
#define LEDColor__control_RemoteCommandsMain_Automatic_calc (LEDColor)
#define Mode__control_RemoteCommandsMain_Automatic_calc (Mode)
#define PulseLeft__control_RemoteCommandsMain_Automatic_calc (PulseLeft)
#define PulseRight__control_RemoteCommandsMain_Automatic_calc (PulseRight)
#define ServoAngle__control_RemoteCommandsMain_Automatic_calc (ServoAngle)
#define TargetSpeed__control_RemoteCommandsMain_Automatic_calc (TargetSpeed)
#define TurnLeftRightFlag__control_RemoteCommandsMain_Automatic_calc (TurnLeftRightFlag)


void control_RemoteCommandsMain_Automatic_calc (void)
{
   esdl_rc_control_RemoteCommandsMain_RAM.mode = Mode__control_RemoteCommandsMain_Automatic_calc;
   control_RemoteCommands_Automatic_trig();
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF PROCESS 'control_RemoteCommandsMain_Automatic_calc'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



