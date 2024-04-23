/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER 7.9.0
 * CODE GENERATOR:..............6.4.7
 * COMPONENT:...................classes.VehicleSpeedController
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

#include "classes_VehicleSpeedController_Automatic.h"
#include "interfaces_IBalance2WD_Automatic.h"
#include "interfaces_IParameters_Automatic.h"


/******************************************************************************
 * BEGIN: DEFINITION OF SUBSTRUCT VARIABLE 'classes_VehicleSpeedController_RAM'
 * ----------------------------------------------------------------------------
 * memory class:.................................'RAM'
 * model name:...................................'classes_VehicleSpeedController'
 * data set:.....................................'CLASSES_VEHICLESPEEDCONTROLLER_AUTOMATIC_esdl_Data_Default'
 * ---------------------------------------------------------------------------*/
struct classes_VehicleSpeedController_Automatic_RAM_SUBSTRUCT classes_VehicleSpeedController_RAM = {
   /* struct element:'classes_VehicleSpeedController_RAM.errorSpeedSum' (modeled as:'errorSpeedSum.classes_VehicleSpeedController') */
   0.0F,
   /* substruct: classes_VehicleSpeedController_RAM.DigitalLowpass_Speed (modeled as:'DigitalLowpass_Speed.classes_VehicleSpeedController') */
   {
      /* struct element:'classes_VehicleSpeedController_RAM.DigitalLowpass_Speed.memory' (modeled as:'memory.DigitalLowpass_Speed.classes_VehicleSpeedController') */
      0.0F
   },
   /* substruct: classes_VehicleSpeedController_RAM.DigitalLowpass_TargetSpeed (modeled as:'DigitalLowpass_TargetSpeed.classes_VehicleSpeedController') */
   {
      /* struct element:'classes_VehicleSpeedController_RAM.DigitalLowpass_TargetSpeed.memory' (modeled as:'memory.DigitalLowpass_TargetSpeed.classes_VehicleSpeedController') */
      0.0F
   },
   /* substruct: classes_VehicleSpeedController_RAM.Integrator_Speed (modeled as:'Integrator_Speed.classes_VehicleSpeedController') */
   {
      /* struct element:'classes_VehicleSpeedController_RAM.Integrator_Speed.memory' (modeled as:'memory.Integrator_Speed.classes_VehicleSpeedController') */
      0.0F
   }
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF SUBSTRUCT VARIABLE 'classes_VehicleSpeedController_RAM'
 ******************************************************************************/

/******************************************************************************
 * BEGIN: DEFINITION OF COMPONENT VARIABLE 'classes_VehicleSpeedController'
 * ----------------------------------------------------------------------------
 * memory class:.................................'ROM'
 * model name:...................................'classes_VehicleSpeedController'
 * data set:.....................................'CLASSES_VEHICLESPEEDCONTROLLER_AUTOMATIC_esdl_Data_Default'
 * ---------------------------------------------------------------------------*/
const struct classes_VehicleSpeedController_Automatic classes_VehicleSpeedController = {
   /* substruct: classes_VehicleSpeedController.DigitalLowpass_Speed (modeled as:'DigitalLowpass_Speed.classes_VehicleSpeedController') */
   {
      /* type descriptor pointer 'SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_RAM' for memory class substruct for 'RAM' */
      &classes_VehicleSpeedController_RAM.DigitalLowpass_Speed
   },
   /* substruct: classes_VehicleSpeedController.DigitalLowpass_TargetSpeed (modeled as:'DigitalLowpass_TargetSpeed.classes_VehicleSpeedController') */
   {
      /* type descriptor pointer 'SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_RAM' for memory class substruct for 'RAM' */
      &classes_VehicleSpeedController_RAM.DigitalLowpass_TargetSpeed
   },
   /* substruct: classes_VehicleSpeedController.Integrator_Speed (modeled as:'Integrator_Speed.classes_VehicleSpeedController') */
   {
      /* type descriptor pointer 'SystemLib_Transferfunction_Integrator_IntegratorKLimited_Automatic_RAM' for memory class substruct for 'RAM' */
      &classes_VehicleSpeedController_RAM.Integrator_Speed
   }
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF COMPONENT VARIABLE 'classes_VehicleSpeedController'
 ******************************************************************************/





#define DigitalLowpass_Speed_REF (&(classes_VehicleSpeedController.DigitalLowpass_Speed))
#define DigitalLowpass_TargetSpeed_REF (&(classes_VehicleSpeedController.DigitalLowpass_TargetSpeed))
#define errorSpeedSum_VAL (classes_VehicleSpeedController_RAM.errorSpeedSum)
#define Integrator_Speed_REF (&(classes_VehicleSpeedController.Integrator_Speed))


/******************************************************************************
 * BEGIN: FUNCTIONS OF COMPONENT
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF PROCESS 'classes_VehicleSpeedController_Automatic_calculateVehicleSpeed'
 * ----------------------------------------------------------------------------
 * model name:...................................'calculateVehicleSpeed'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/
/* messages used by this process */
#define KiSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (KiSpeed)
#define KpSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (KpSpeed)
#define PulseLeft__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (PulseLeft)
#define PulseRight__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (PulseRight)
#define SpeedOutput__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (SpeedOutput)
#define TargetSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (TargetSpeed)


void classes_VehicleSpeedController_Automatic_calculateVehicleSpeed (void)
{
   /* user defined local variables */
   float32 currentSpeed;
   float32 errorSpeed;
   sint32 measuredSpeed;
   /* temp. variables */
   sint32 _t1sint32;

   measuredSpeed = 0;
   currentSpeed = 0.0F;
   errorSpeed = 0.0F;
   _t1sint32
      = (PulseLeft__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed / 2) + (PulseRight__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed / 2);
   measuredSpeed
      = ((_t1sint32 >= -1073741824) ? (((_t1sint32 <= 1073741823L) ? (_t1sint32 * 2) : 2147483647L)) : (sint32)SINT32_MIN);
   SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_compute(DigitalLowpass_Speed_REF, (float32)measuredSpeed, 0.3F);
   currentSpeed
      = SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_value(DigitalLowpass_Speed_REF);
   SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_compute(DigitalLowpass_TargetSpeed_REF, TargetSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed, 0.05F);
   PulseLeft__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed = 0;
   PulseRight__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed = 0;
   errorSpeed
      = currentSpeed - SystemLib_Transferfunction_Lowpass_DigitalLowpass_Automatic_value(DigitalLowpass_TargetSpeed_REF);
   SystemLib_Transferfunction_Integrator_IntegratorKLimited_Automatic_compute(Integrator_Speed_REF, errorSpeed, 1.0F, -227.5F, 227.5F);
   errorSpeedSum_VAL
      = SystemLib_Transferfunction_Integrator_IntegratorKLimited_Automatic_value(Integrator_Speed_REF);
   SpeedOutput__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed
      = (KpSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed * errorSpeed) + (errorSpeedSum_VAL * KiSpeed__classes_VehicleSpeedController_Automatic_calculateVehicleSpeed);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF PROCESS 'classes_VehicleSpeedController_Automatic_calculateVehicleSpeed'
 ******************************************************************************/




/******************************************************************************
 * BEGIN: DEFINITION OF METHOD 'classes_VehicleSpeedController_Automatic_init'
 * ----------------------------------------------------------------------------
 * model name:...................................'init'
 * memory class:.................................'CODE'
 * ---------------------------------------------------------------------------*/

void classes_VehicleSpeedController_Automatic_init (void)
{
   SystemLib_Transferfunction_Integrator_IntegratorKLimited_Automatic_reset(Integrator_Speed_REF, 0.0F);
}
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF METHOD 'classes_VehicleSpeedController_Automatic_init'
 ******************************************************************************/



/* ****************************************************************************
 * END: FUNCTIONS OF COMPONENT
 ******************************************************************************/



