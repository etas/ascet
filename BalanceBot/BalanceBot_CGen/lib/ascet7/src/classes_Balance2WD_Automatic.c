/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................classes.Balance2WD
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

#include "classes_Balance2WD_Automatic.h"
#include "interfaces_IBalance2WD_Automatic.h"
#include "interfaces_IParameters_Automatic.h"


/******************************************************************************
 * BEGIN: DEFINITION OF SUBSTRUCT VARIABLE 'control_RemoteCommandsMain_Balance2WD_RAM'
 * ----------------------------------------------------------------------------
 * memory class:.................................'RAM'
 * model name:...................................'control_RemoteCommandsMain_Balance2WD'
 * data set:.....................................'CLASSES_BALANCE2WD_AUTOMATIC_esdl_Data_Default'
 * ---------------------------------------------------------------------------*/
struct classes_Balance2WD_Automatic_RAM_SUBSTRUCT control_RemoteCommandsMain_Balance2WD_RAM = {
   /* struct element:'control_RemoteCommandsMain_Balance2WD_RAM.enginesOn' (modeled as:'enginesOn.control_RemoteCommandsMain_Balance2WD') */
   0,
   /* struct element:'control_RemoteCommandsMain_Balance2WD_RAM.frontDistance' (modeled as:'frontDistance.control_RemoteCommandsMain_Balance2WD') */
   0.0F
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF SUBSTRUCT VARIABLE 'control_RemoteCommandsMain_Balance2WD_RAM'
 ******************************************************************************/

/******************************************************************************
 * DEFINITION OF COMPONENT VARIABLE OMITTED
 * ----------------------------------------------------------------------------
 * memory class:.................................'ROM'
 * model name:...................................'control_RemoteCommandsMain_Balance2WD'
 * reason:.......................................no local elements
 * ---------------------------------------------------------------------------*/





#define enginesOn_VAL (control_RemoteCommandsMain_Balance2WD_RAM.enginesOn)
#define frontDistance_VAL (control_RemoteCommandsMain_Balance2WD_RAM.frontDistance)


/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_buzzerOff'
 * ----------------------------------------------------------------------------
 * model name:...................................'buzzerOff'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define BuzzerOn__classes_Balance2WD_Automatic_buzzerOff (BuzzerOn)


void classes_Balance2WD_Automatic_buzzerOff (void)
{
   BuzzerOn__classes_Balance2WD_Automatic_buzzerOff = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_buzzerOff'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_buzzerOn'
 * ----------------------------------------------------------------------------
 * model name:...................................'buzzerOn'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define BuzzerOn__classes_Balance2WD_Automatic_buzzerOn (BuzzerOn)


void classes_Balance2WD_Automatic_buzzerOn (void)
{
   BuzzerOn__classes_Balance2WD_Automatic_buzzerOn = 1;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_buzzerOn'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculateFrontDistance'
 * ----------------------------------------------------------------------------
 * model name:...................................'calculateFrontDistance'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define UltraSonicSignalRuntimeInMicroSeconds__classes_Balance2WD_Automatic_calculateFrontDistance (UltraSonicSignalRuntimeInMicroSeconds)


void classes_Balance2WD_Automatic_calculateFrontDistance (void)
{
   frontDistance_VAL
      = (float32)UltraSonicSignalRuntimeInMicroSeconds__classes_Balance2WD_Automatic_calculateFrontDistance * 0.017F;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculateFrontDistance'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculateMotorPower'
 * ----------------------------------------------------------------------------
 * model name:...................................'calculateMotorPower'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define AngleOutput__classes_Balance2WD_Automatic_calculateMotorPower (AngleOutput)
#define CurrentAngle__classes_Balance2WD_Automatic_calculateMotorPower (CurrentAngle)
#define PWM1__classes_Balance2WD_Automatic_calculateMotorPower (PWM1)
#define PWM2__classes_Balance2WD_Automatic_calculateMotorPower (PWM2)
#define SpeedOutput__classes_Balance2WD_Automatic_calculateMotorPower (SpeedOutput)
#define TurnOutput__classes_Balance2WD_Automatic_calculateMotorPower (TurnOutput)


void classes_Balance2WD_Automatic_calculateMotorPower (void)
{
   /* user defined local variables */
   float32 pwm;

   pwm = 0.0F;
   if ((((CurrentAngle__classes_Balance2WD_Automatic_calculateMotorPower > 0.0F) ? CurrentAngle__classes_Balance2WD_Automatic_calculateMotorPower : -CurrentAngle__classes_Balance2WD_Automatic_calculateMotorPower)) > 40.0F)
   {
      classes_Balance2WD_Automatic_setEnginesOff();
   } /* end if */
   if (enginesOn_VAL == 0)
   {
      PWM1__classes_Balance2WD_Automatic_calculateMotorPower = 0.0F;
      PWM2__classes_Balance2WD_Automatic_calculateMotorPower = 0.0F;
      return;
   } /* end if */
   pwm
      = AngleOutput__classes_Balance2WD_Automatic_calculateMotorPower + SpeedOutput__classes_Balance2WD_Automatic_calculateMotorPower;
   PWM1__classes_Balance2WD_Automatic_calculateMotorPower
      = pwm - TurnOutput__classes_Balance2WD_Automatic_calculateMotorPower;
   PWM2__classes_Balance2WD_Automatic_calculateMotorPower
      = pwm + TurnOutput__classes_Balance2WD_Automatic_calculateMotorPower;
   PWM1__classes_Balance2WD_Automatic_calculateMotorPower
      = SystemLib_Nonlinears_Limiter_Automatic_value(-255.0F, PWM1__classes_Balance2WD_Automatic_calculateMotorPower, 255.0F);
   PWM2__classes_Balance2WD_Automatic_calculateMotorPower
      = SystemLib_Nonlinears_Limiter_Automatic_value(-255.0F, PWM2__classes_Balance2WD_Automatic_calculateMotorPower, 255.0F);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculateMotorPower'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculatePulseCount'
 * ----------------------------------------------------------------------------
 * model name:...................................'calculatePulseCount'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define CountLeft__classes_Balance2WD_Automatic_calculatePulseCount (CountLeft)
#define CountRight__classes_Balance2WD_Automatic_calculatePulseCount (CountRight)
#define PWM1__classes_Balance2WD_Automatic_calculatePulseCount (PWM1)
#define PWM2__classes_Balance2WD_Automatic_calculatePulseCount (PWM2)
#define PulseLeft__classes_Balance2WD_Automatic_calculatePulseCount (PulseLeft)
#define PulseRight__classes_Balance2WD_Automatic_calculatePulseCount (PulseRight)


void classes_Balance2WD_Automatic_calculatePulseCount (void)
{
   /* user defined local variables */
   sint32 leftPulse;
   sint32 rightPulse;
   /* temp. variables */
   sint32 _t1sint32;

   leftPulse = CountLeft__classes_Balance2WD_Automatic_calculatePulseCount;
   rightPulse = CountRight__classes_Balance2WD_Automatic_calculatePulseCount;
   CountLeft__classes_Balance2WD_Automatic_calculatePulseCount = 0;
   CountRight__classes_Balance2WD_Automatic_calculatePulseCount = 0;
   if (PWM1__classes_Balance2WD_Automatic_calculatePulseCount < 0.0F)
   {
      leftPulse = ((leftPulse > -2147483647) ? -leftPulse : 2147483647L);
   } /* end if */
   if (PWM2__classes_Balance2WD_Automatic_calculatePulseCount < 0.0F)
   {
      rightPulse = ((rightPulse > -2147483647) ? -rightPulse : 2147483647L);
   } /* end if */
   _t1sint32
      = (PulseLeft__classes_Balance2WD_Automatic_calculatePulseCount / 2) + (leftPulse / 2);
   PulseLeft__classes_Balance2WD_Automatic_calculatePulseCount
      = ((_t1sint32 >= -1073741824) ? (((_t1sint32 <= 1073741823L) ? (_t1sint32 * 2) : 2147483647L)) : (sint32)SINT32_MIN);
   _t1sint32
      = (PulseRight__classes_Balance2WD_Automatic_calculatePulseCount / 2) + (rightPulse / 2);
   PulseRight__classes_Balance2WD_Automatic_calculatePulseCount
      = ((_t1sint32 >= -1073741824) ? (((_t1sint32 <= 1073741823L) ? (_t1sint32 * 2) : 2147483647L)) : (sint32)SINT32_MIN);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF PROCESS 'classes_Balance2WD_Automatic_calculatePulseCount'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_getFrontDistance'
 * ----------------------------------------------------------------------------
 * model name:...................................'getFrontDistance'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

float32 classes_Balance2WD_Automatic_getFrontDistance (void)
{
   return frontDistance_VAL;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_getFrontDistance'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_goBackward'
 * ----------------------------------------------------------------------------
 * model name:...................................'goBackward'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void classes_Balance2WD_Automatic_goBackward (void)
{
   classes_Balance2WD_Automatic_setTargetSpeed(-50.0F);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_goBackward'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_goForward'
 * ----------------------------------------------------------------------------
 * model name:...................................'goForward'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void classes_Balance2WD_Automatic_goForward (void)
{
   classes_Balance2WD_Automatic_setTargetSpeed(50.0F);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_goForward'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_moveServoToBalancingPosition'
 * ----------------------------------------------------------------------------
 * model name:...................................'moveServoToBalancingPosition'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define ServoAngle__classes_Balance2WD_Automatic_moveServoToBalancingPosition (ServoAngle)


void classes_Balance2WD_Automatic_moveServoToBalancingPosition (void)
{
   ServoAngle__classes_Balance2WD_Automatic_moveServoToBalancingPosition = 80;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_moveServoToBalancingPosition'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_moveServoToParkingPosition'
 * ----------------------------------------------------------------------------
 * model name:...................................'moveServoToParkingPosition'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define ServoAngle__classes_Balance2WD_Automatic_moveServoToParkingPosition (ServoAngle)


void classes_Balance2WD_Automatic_moveServoToParkingPosition (void)
{
   ServoAngle__classes_Balance2WD_Automatic_moveServoToParkingPosition = 20;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_moveServoToParkingPosition'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_resetBalancerCounters'
 * ----------------------------------------------------------------------------
 * model name:...................................'resetBalancerCounters'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define CountLeft__classes_Balance2WD_Automatic_resetBalancerCounters (CountLeft)
#define CountRight__classes_Balance2WD_Automatic_resetBalancerCounters (CountRight)
#define PulseLeft__classes_Balance2WD_Automatic_resetBalancerCounters (PulseLeft)
#define PulseRight__classes_Balance2WD_Automatic_resetBalancerCounters (PulseRight)


void classes_Balance2WD_Automatic_resetBalancerCounters (void)
{
   CountLeft__classes_Balance2WD_Automatic_resetBalancerCounters = 0;
   CountRight__classes_Balance2WD_Automatic_resetBalancerCounters = 0;
   PulseLeft__classes_Balance2WD_Automatic_resetBalancerCounters = 0;
   PulseRight__classes_Balance2WD_Automatic_resetBalancerCounters = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_resetBalancerCounters'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setEnginesOff'
 * ----------------------------------------------------------------------------
 * model name:...................................'setEnginesOff'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void classes_Balance2WD_Automatic_setEnginesOff (void)
{
   enginesOn_VAL = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setEnginesOff'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setEnginesOn'
 * ----------------------------------------------------------------------------
 * model name:...................................'setEnginesOn'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void classes_Balance2WD_Automatic_setEnginesOn (void)
{
   enginesOn_VAL = 1;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setEnginesOn'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsBlue'
 * ----------------------------------------------------------------------------
 * model name:...................................'setLEDsBlue'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define LEDColor__classes_Balance2WD_Automatic_setLEDsBlue (LEDColor)


void classes_Balance2WD_Automatic_setLEDsBlue (void)
{
   LEDColor__classes_Balance2WD_Automatic_setLEDsBlue = 3;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsBlue'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsGreen'
 * ----------------------------------------------------------------------------
 * model name:...................................'setLEDsGreen'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define LEDColor__classes_Balance2WD_Automatic_setLEDsGreen (LEDColor)


void classes_Balance2WD_Automatic_setLEDsGreen (void)
{
   LEDColor__classes_Balance2WD_Automatic_setLEDsGreen = 2;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsGreen'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsOff'
 * ----------------------------------------------------------------------------
 * model name:...................................'setLEDsOff'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define LEDColor__classes_Balance2WD_Automatic_setLEDsOff (LEDColor)


void classes_Balance2WD_Automatic_setLEDsOff (void)
{
   LEDColor__classes_Balance2WD_Automatic_setLEDsOff = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsOff'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsRed'
 * ----------------------------------------------------------------------------
 * model name:...................................'setLEDsRed'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define LEDColor__classes_Balance2WD_Automatic_setLEDsRed (LEDColor)


void classes_Balance2WD_Automatic_setLEDsRed (void)
{
   LEDColor__classes_Balance2WD_Automatic_setLEDsRed = 1;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsRed'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsYellow'
 * ----------------------------------------------------------------------------
 * model name:...................................'setLEDsYellow'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define LEDColor__classes_Balance2WD_Automatic_setLEDsYellow (LEDColor)


void classes_Balance2WD_Automatic_setLEDsYellow (void)
{
   LEDColor__classes_Balance2WD_Automatic_setLEDsYellow = 4;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setLEDsYellow'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setTargetSpeed'
 * ----------------------------------------------------------------------------
 * model name:...................................'setTargetSpeed'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define TargetSpeed__classes_Balance2WD_Automatic_setTargetSpeed (TargetSpeed)


void classes_Balance2WD_Automatic_setTargetSpeed (/* IN    */ const float32 targetSpeed)
{
   TargetSpeed__classes_Balance2WD_Automatic_setTargetSpeed = targetSpeed;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_setTargetSpeed'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_stop'
 * ----------------------------------------------------------------------------
 * model name:...................................'stop'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define TurnLeftRightFlag__classes_Balance2WD_Automatic_stop (TurnLeftRightFlag)


void classes_Balance2WD_Automatic_stop (void)
{
   classes_Balance2WD_Automatic_setTargetSpeed(0.0F);
   TurnLeftRightFlag__classes_Balance2WD_Automatic_stop = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_stop'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_stopTurning'
 * ----------------------------------------------------------------------------
 * model name:...................................'stopTurning'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define TurnLeftRightFlag__classes_Balance2WD_Automatic_stopTurning (TurnLeftRightFlag)


void classes_Balance2WD_Automatic_stopTurning (void)
{
   TurnLeftRightFlag__classes_Balance2WD_Automatic_stopTurning = 0;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_stopTurning'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_turnLeft'
 * ----------------------------------------------------------------------------
 * model name:...................................'turnLeft'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define TurnLeftRightFlag__classes_Balance2WD_Automatic_turnLeft (TurnLeftRightFlag)


void classes_Balance2WD_Automatic_turnLeft (void)
{
   TurnLeftRightFlag__classes_Balance2WD_Automatic_turnLeft = -1;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_turnLeft'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_turnRight'
 * ----------------------------------------------------------------------------
 * model name:...................................'turnRight'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define TurnLeftRightFlag__classes_Balance2WD_Automatic_turnRight (TurnLeftRightFlag)


void classes_Balance2WD_Automatic_turnRight (void)
{
   TurnLeftRightFlag__classes_Balance2WD_Automatic_turnRight = 1;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_Balance2WD_Automatic_turnRight'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



