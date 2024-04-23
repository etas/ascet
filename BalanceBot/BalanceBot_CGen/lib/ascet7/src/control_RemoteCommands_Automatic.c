/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................control.RemoteCommands
 * REPRESENTATION:..............Automatic
 * DESCRIPTION:
 *    
 ******************************************************************************/



/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "control_RemoteCommands_Automatic.h"
#include "classes_Balance2WD_Automatic.h"
#include "control_RemoteCommandsMain_Automatic.h"
/******************************************************************************
 * BEGIN: source code of a single instance class
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF SUBSTRUCT VARIABLE 'esdl_rc_control_RemoteCommandsMain_RAM'
 * ----------------------------------------------------------------------------
 * memory class:.................................'RAM'
 * model name:...................................'rc'
 * data set:.....................................'CONTROL_REMOTECOMMANDS_AUTOMATIC_esdl_Data_Default'
 * ---------------------------------------------------------------------------*/
struct control_RemoteCommands_Automatic_RAM_SUBSTRUCT esdl_rc_control_RemoteCommandsMain_RAM = {
   /* struct element:'esdl_rc_control_RemoteCommandsMain_RAM.counter' (modeled as:'counter.rc') */
   0,
   /* struct element:'esdl_rc_control_RemoteCommandsMain_RAM.mode' (modeled as:'mode.rc') */
   control_EModes_STOP_BALANCING,
   /* struct element:'esdl_rc_control_RemoteCommandsMain_RAM.sm' (modeled as:'sm.rc') */
   0U /* Dispatch */
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF SUBSTRUCT VARIABLE 'esdl_rc_control_RemoteCommandsMain_RAM'
 ******************************************************************************/

/******************************************************************************
 * DEFINITION OF COMPONENT VARIABLE OMITTED
 * ----------------------------------------------------------------------------
 * memory class:.................................'ROM'
 * model name:...................................'rc'
 * reason:.......................................no local elements
 * ---------------------------------------------------------------------------*/





#define mode_VAL (esdl_rc_control_RemoteCommandsMain_RAM.mode)
#define sm_VAL (esdl_rc_control_RemoteCommandsMain_RAM.sm)

/*-----------------------------------------------------------------------------
 *    Defines
 *----------------------------------------------------------------------------*/


/* definition of label "Dispatch" from enumeration "control_RemoteCommands_enum" */
#define Dispatch 0U
/* definition of label "Driving" from enumeration "control_RemoteCommands_enum" */
#define Driving 1U
/* definition of label "FarObstacleDetected" from enumeration "control_RemoteCommands_enum" */
#define FarObstacleDetected 2U
/* definition of label "GoBackward" from enumeration "control_RemoteCommands_enum" */
#define GoBackward 3U
/* definition of label "GoForward" from enumeration "control_RemoteCommands_enum" */
#define GoForward 4U
/* definition of label "MovingForward" from enumeration "control_RemoteCommands_enum" */
#define MovingForward 5U
/* definition of label "NearObstacleDetected" from enumeration "control_RemoteCommands_enum" */
#define NearObstacleDetected 6U
/* definition of label "Parked" from enumeration "control_RemoteCommands_enum" */
#define Parked 7U
/* definition of label "Stabilizing" from enumeration "control_RemoteCommands_enum" */
#define Stabilizing 8U
/* definition of label "StartBalancing" from enumeration "control_RemoteCommands_enum" */
#define StartBalancing 9U
/* definition of label "Starting" from enumeration "control_RemoteCommands_enum" */
#define Starting 10U
/* definition of label "Stop" from enumeration "control_RemoteCommands_enum" */
#define Stop 11U
/* definition of label "StopBalancing" from enumeration "control_RemoteCommands_enum" */
#define StopBalancing 12U
/* definition of label "StopTurning" from enumeration "control_RemoteCommands_enum" */
#define StopTurning 13U
/* definition of label "TurnLeft" from enumeration "control_RemoteCommands_enum" */
#define TurnLeft 14U
/* definition of label "TurnRight" from enumeration "control_RemoteCommands_enum" */
#define TurnRight 15U


/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsGoBackwardMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsGoBackwardMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsGoBackwardMode (void)
{
   return mode_VAL == control_EModes_GO_BACKWARD;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsGoBackwardMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsGoForwardMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsGoForwardMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsGoForwardMode (void)
{
   return mode_VAL == control_EModes_GO_FORWARD;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsGoForwardMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsManualDriveMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsManualDriveMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsManualDriveMode (void)
{
   return (control_RemoteCommands_Automatic_IsStopMode()) || (control_RemoteCommands_Automatic_IsStopBalancingMode()) || (control_RemoteCommands_Automatic_IsGoForwardMode()) || (control_RemoteCommands_Automatic_IsGoBackwardMode()) || (control_RemoteCommands_Automatic_IsTurnLeftMode()) || (control_RemoteCommands_Automatic_IsTurnRightMode()) || (control_RemoteCommands_Automatic_IsStopTurningMode());
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsManualDriveMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsObstacleAvoidanceMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsObstacleAvoidanceMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsObstacleAvoidanceMode (void)
{
   return mode_VAL == control_EModes_OBSTACLE_AVOIDANCE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsObstacleAvoidanceMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsOpenLabMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsOpenLabMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsOpenLabMode (void)
{
   return mode_VAL == control_EModes_OPENLAB_MODE;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsOpenLabMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopBalancingMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsStopBalancingMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsStopBalancingMode (void)
{
   return mode_VAL == control_EModes_STOP_BALANCING;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopBalancingMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsStopMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsStopMode (void)
{
   return mode_VAL == control_EModes_STOP;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopTurningMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsStopTurningMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsStopTurningMode (void)
{
   return mode_VAL == control_EModes_STOP_TURNING;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsStopTurningMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsTurnLeftMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsTurnLeftMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsTurnLeftMode (void)
{
   return mode_VAL == control_EModes_TURN_LEFT;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsTurnLeftMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsTurnRightMode'
 * ----------------------------------------------------------------------------
 * model name:...................................'IsTurnRightMode'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

esdl_boolean control_RemoteCommands_Automatic_IsTurnRightMode (void)
{
   return mode_VAL == control_EModes_TURN_RIGHT;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_IsTurnRightMode'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_trig'
 * ----------------------------------------------------------------------------
 * model name:...................................'trig'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void control_RemoteCommands_Automatic_trig (void)
{
   switch (sm_VAL)
   {
      case Driving:
         if (!control_RemoteCommands_Automatic_IsOpenLabMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         break;
      case FarObstacleDetected:
         if (!control_RemoteCommands_Automatic_IsObstacleAvoidanceMode())
         {
            classes_Balance2WD_Automatic_stopTurning();
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (SystemLib_CounterTimer_Timer_Automatic_isElapsed())
         {
            classes_Balance2WD_Automatic_stopTurning();
            classes_Balance2WD_Automatic_goForward();
            sm_VAL = MovingForward;
            break;
         } /* end if */
         SystemLib_CounterTimer_Timer_Automatic_compute();
         break;
      case GoBackward:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsGoBackwardMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case GoForward:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsGoForwardMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case MovingForward:
         if (!control_RemoteCommands_Automatic_IsObstacleAvoidanceMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (classes_Balance2WD_Automatic_getFrontDistance() <= 30.0F)
         {
            classes_Balance2WD_Automatic_stop();
            classes_Balance2WD_Automatic_goBackward();
            SystemLib_CounterTimer_Timer_Automatic_begin(2.0F);
            sm_VAL = NearObstacleDetected;
            break;
         } /* end if */
         if (classes_Balance2WD_Automatic_getFrontDistance() <= 50.0F)
         {
            classes_Balance2WD_Automatic_turnLeft();
            SystemLib_CounterTimer_Timer_Automatic_begin(0.2F);
            sm_VAL = FarObstacleDetected;
            break;
         } /* end if */
         break;
      case NearObstacleDetected:
         if (!control_RemoteCommands_Automatic_IsObstacleAvoidanceMode())
         {
            classes_Balance2WD_Automatic_stop();
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (SystemLib_CounterTimer_Timer_Automatic_isElapsed())
         {
            classes_Balance2WD_Automatic_stop();
            classes_Balance2WD_Automatic_turnLeft();
            SystemLib_CounterTimer_Timer_Automatic_begin(0.2F);
            sm_VAL = FarObstacleDetected;
            break;
         } /* end if */
         SystemLib_CounterTimer_Timer_Automatic_compute();
         break;
      case Parked:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsStopBalancingMode())
         {
            if (!control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setEnginesOn();
               classes_Balance2WD_Automatic_moveServoToBalancingPosition();
            } /* end if */
            sm_VAL = StartBalancing;
            break;
         } /* end if */
         break;
      case Stabilizing:
         if (!control_RemoteCommands_Automatic_IsObstacleAvoidanceMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (SystemLib_CounterTimer_Timer_Automatic_isElapsed())
         {
            classes_Balance2WD_Automatic_goForward();
            sm_VAL = MovingForward;
            break;
         } /* end if */
         SystemLib_CounterTimer_Timer_Automatic_compute();
         break;
      case StartBalancing:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsTurnLeftMode())
         {
            classes_Balance2WD_Automatic_turnLeft();
            sm_VAL = TurnLeft;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsGoForwardMode())
         {
            classes_Balance2WD_Automatic_goForward();
            classes_Balance2WD_Automatic_setLEDsGreen();
            sm_VAL = GoForward;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsTurnRightMode())
         {
            classes_Balance2WD_Automatic_turnRight();
            sm_VAL = TurnRight;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsGoBackwardMode())
         {
            classes_Balance2WD_Automatic_goBackward();
            classes_Balance2WD_Automatic_setLEDsBlue();
            sm_VAL = GoBackward;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsStopBalancingMode())
         {
            classes_Balance2WD_Automatic_setLEDsRed();
            classes_Balance2WD_Automatic_moveServoToParkingPosition();
            SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
            classes_Balance2WD_Automatic_goBackward();
            sm_VAL = StopBalancing;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsStopTurningMode())
         {
            classes_Balance2WD_Automatic_stopTurning();
            sm_VAL = StopTurning;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsStopMode())
         {
            classes_Balance2WD_Automatic_setLEDsRed();
            classes_Balance2WD_Automatic_stop();
            sm_VAL = Stop;
            break;
         } /* end if */
         break;
      case Starting:
         if (!control_RemoteCommands_Automatic_IsOpenLabMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (SystemLib_CounterTimer_Timer_Automatic_isElapsed())
         {
            sm_VAL = Driving;
            break;
         } /* end if */
         SystemLib_CounterTimer_Timer_Automatic_compute();
         break;
      case Stop:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsStopMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case StopBalancing:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (SystemLib_CounterTimer_Timer_Automatic_isElapsed())
         {
            classes_Balance2WD_Automatic_stop();
            classes_Balance2WD_Automatic_setEnginesOff();
            classes_Balance2WD_Automatic_resetBalancerCounters();
            sm_VAL = Parked;
            break;
         } /* end if */
         SystemLib_CounterTimer_Timer_Automatic_compute();
         break;
      case StopTurning:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsStopTurningMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case TurnLeft:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            classes_Balance2WD_Automatic_stopTurning();
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsTurnLeftMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case TurnRight:
         if (!control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            classes_Balance2WD_Automatic_stopTurning();
            sm_VAL = Dispatch;
            break;
         } /* end if */
         if (!control_RemoteCommands_Automatic_IsTurnRightMode())
         {
            if (control_RemoteCommands_Automatic_IsTurnLeftMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_turnLeft();
               sm_VAL = TurnLeft;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoForwardMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_goForward();
               classes_Balance2WD_Automatic_setLEDsGreen();
               sm_VAL = GoForward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsTurnRightMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_turnRight();
               sm_VAL = TurnRight;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsGoBackwardMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_goBackward();
               classes_Balance2WD_Automatic_setLEDsBlue();
               sm_VAL = GoBackward;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_moveServoToParkingPosition();
               SystemLib_CounterTimer_Timer_Automatic_begin(0.8F);
               classes_Balance2WD_Automatic_goBackward();
               sm_VAL = StopBalancing;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopTurningMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_stopTurning();
               sm_VAL = StopTurning;
               break;
            } /* end if */
            if (control_RemoteCommands_Automatic_IsStopMode())
            {
               classes_Balance2WD_Automatic_stopTurning();
               classes_Balance2WD_Automatic_setLEDsRed();
               classes_Balance2WD_Automatic_stop();
               sm_VAL = Stop;
               break;
            } /* end if */
         } /* end if */
         break;
      case Dispatch:
      default:
         if (control_RemoteCommands_Automatic_IsManualDriveMode())
         {
            if (!control_RemoteCommands_Automatic_IsStopBalancingMode())
            {
               classes_Balance2WD_Automatic_setEnginesOn();
               classes_Balance2WD_Automatic_moveServoToBalancingPosition();
            } /* end if */
            sm_VAL = StartBalancing;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsObstacleAvoidanceMode())
         {
            classes_Balance2WD_Automatic_stop();
            classes_Balance2WD_Automatic_setLEDsYellow();
            SystemLib_CounterTimer_Timer_Automatic_begin(1.0F);
            sm_VAL = Stabilizing;
            break;
         } /* end if */
         if (control_RemoteCommands_Automatic_IsOpenLabMode())
         {
            classes_Balance2WD_Automatic_stop();
            classes_Balance2WD_Automatic_setLEDsYellow();
            SystemLib_CounterTimer_Timer_Automatic_begin(1.0F);
            sm_VAL = Starting;
            break;
         } /* end if */
         break;
   } /* end switch */
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'control_RemoteCommands_Automatic_trig'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



