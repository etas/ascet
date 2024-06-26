/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................SystemLib.CounterTimer.Timer
 * REPRESENTATION:..............Automatic
 * DESCRIPTION:
 *    Timer decrements the time counter by dT and signals when the time counter has reached zero. It is not retriggerable.
 ******************************************************************************/



/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "SystemLib_CounterTimer_Timer_Automatic.h"
#include "BalanceTube_STMicro_Automatic.h"
/******************************************************************************
 * BEGIN: source code of a multiple instance class
 ******************************************************************************/



#define dT_VAL (ASD_DT_SCALED)
#define timeCounter_VAL (self->SystemLib_CounterTimer_Timer_Automatic_RAM->timeCounter)


/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_begin'
 * ----------------------------------------------------------------------------
 * model name:...................................'begin'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void SystemLib_CounterTimer_Timer_Automatic_begin (
               const struct SystemLib_CounterTimer_Timer_Automatic * self,
   /* IN    */ const float32                                         startTime
   )
{
   timeCounter_VAL = startTime;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_begin'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_compute'
 * ----------------------------------------------------------------------------
 * model name:...................................'compute'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void SystemLib_CounterTimer_Timer_Automatic_compute ( const struct SystemLib_CounterTimer_Timer_Automatic * self)
{
   timeCounter_VAL
      = ((timeCounter_VAL > dT_VAL) ? (timeCounter_VAL - dT_VAL) : 0.0F);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_compute'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_getTime'
 * ----------------------------------------------------------------------------
 * model name:...................................'getTime'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

float32 SystemLib_CounterTimer_Timer_Automatic_getTime ( const struct SystemLib_CounterTimer_Timer_Automatic * self)
{
   return timeCounter_VAL;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_getTime'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_isElapsed'
 * ----------------------------------------------------------------------------
 * model name:...................................'isElapsed'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

boolean SystemLib_CounterTimer_Timer_Automatic_isElapsed ( const struct SystemLib_CounterTimer_Timer_Automatic * self)
{
   return timeCounter_VAL <= 0.0F;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_CounterTimer_Timer_Automatic_isElapsed'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



