/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................SystemLib.Miscellaneous.EdgeRising
 * REPRESENTATION:..............Impl
 * DESCRIPTION:
 *    EdgeRising detects a rising edge of the logical input signal.
 ******************************************************************************/



/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "SystemLib_Miscellaneous_EdgeRising_Impl.h"
/******************************************************************************
 * BEGIN: source code of a multiple instance class
 ******************************************************************************/



#define buffer_VAL (self->SystemLib_Miscellaneous_EdgeRising_Impl_RAM->buffer)
#define oldSignal_VAL (self->SystemLib_Miscellaneous_EdgeRising_Impl_RAM->oldSignal)


/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_Miscellaneous_EdgeRising_Impl_compute'
 * ----------------------------------------------------------------------------
 * model name:...................................'compute'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void SystemLib_Miscellaneous_EdgeRising_Impl_compute (
               const struct SystemLib_Miscellaneous_EdgeRising_Impl * self,
   /* IN    */ const uint8                                            signal
   )
{
   buffer_VAL = signal && (!oldSignal_VAL);
   oldSignal_VAL = signal;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_Miscellaneous_EdgeRising_Impl_compute'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'SystemLib_Miscellaneous_EdgeRising_Impl_value'
 * ----------------------------------------------------------------------------
 * model name:...................................'value'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

uint8 SystemLib_Miscellaneous_EdgeRising_Impl_value ( const struct SystemLib_Miscellaneous_EdgeRising_Impl * self)
{
   return buffer_VAL;
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'SystemLib_Miscellaneous_EdgeRising_Impl_value'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



