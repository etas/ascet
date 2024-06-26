/******************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED BY:..ASCET-DEVELOPER V7.5.0
 * CODE GENERATOR:..............V7.5.0
 * COMPONENT:...................ascet.APP.APP_LeverSelection
 * REPRESENTATION:..............EVB
 * DESCRIPTION:
 *    
 ******************************************************************************/
#ifndef _ASD_APP_LEVERSELECTION_EVB_H_
#define _ASD_APP_LEVERSELECTION_EVB_H_


/*-----------------------------------------------------------------------------
 *    Include files
 *----------------------------------------------------------------------------*/

#include "esdl.h"
#include "sysconsts.h"
#include "chartab.h"
#include "APP_SwitchInterpretation_EVB.h"
#include "T_LeverOut_EVB.h"


/******************************************************************************
 * BEGIN: DEFINITION OF MEMORY CLASS STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 * ----------------------------------------------------------------------------
 * memory class:.................................'EFLASH'
 * ---------------------------------------------------------------------------*/
struct APP_LEVERSELECTION_EVB_EFLASH_SUBSTRUCT {
   uint16 APP_MINUSSWITCHMAX;	/* min=0.0, max=5.0, f_anin, limit=yes */
   uint16 APP_MINUSSWITCHMIN;	/* min=0.0, max=5.0, f_anin, limit=yes */
   uint16 APP_PLUSSWITCHMAX;	/* min=0.0, max=5.0, f_anin, limit=yes */
   uint16 APP_PLUSSWITCHMIN;	/* min=0.0, max=5.0, f_anin, limit=yes */
   boolean APP_ANALOGUEPLUSMINUS;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_DRIVESWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_MANUALSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_MINUSSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_NEUTRALSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_PARKSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_PLUSSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_REVERSESWFITTED;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_SPORTSWFITTED;	/* min=0, max=1, Identity, limit=yes */
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_DriveSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_ManualSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_MinusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_NeutralSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_ParkSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_PlusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_ReverseSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_EFLASH_SUBSTRUCT APP_SportSwitchInterp;
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF MEMORY CLASS STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF MEMORY CLASS STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 * ----------------------------------------------------------------------------
 * memory class:.................................'IRAM'
 * ---------------------------------------------------------------------------*/
struct APP_LEVERSELECTION_EVB_IRAM_SUBSTRUCT {
   boolean APP_AnalogueMinus;	/* min=0, max=1, Identity, limit=yes */
   boolean APP_AnaloguePlus;	/* min=0, max=1, Identity, limit=yes */
   struct T_LEVEROUT_EVB APP_LeverSwitch;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_DriveSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_ManualSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_MinusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_NeutralSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_ParkSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_PlusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_ReverseSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB_IRAM_SUBSTRUCT APP_SportSwitchInterp;
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF MEMORY CLASS STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 ******************************************************************************/


/******************************************************************************
 * BEGIN: DEFINITION OF MAIN STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 * ----------------------------------------------------------------------------
 * memory class:.................................'IFLASH'
 * ---------------------------------------------------------------------------*/
struct APP_LEVERSELECTION_EVB {
   struct APP_LEVERSELECTION_EVB_EFLASH_SUBSTRUCT * APP_LEVERSELECTION_EVB_EFLASH;
   struct APP_LEVERSELECTION_EVB_IRAM_SUBSTRUCT * APP_LEVERSELECTION_EVB_IRAM;
   struct APP_SWITCHINTERPRETATION_EVB APP_DriveSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_ManualSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_MinusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_NeutralSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_ParkSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_PlusSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_ReverseSwitchInterp;
   struct APP_SWITCHINTERPRETATION_EVB APP_SportSwitchInterp;
};
/* ----------------------------------------------------------------------------
 * END: DEFINITION OF MAIN STRUCTURE FOR CLASS 'APP_LEVERSELECTION_EVB'
 ******************************************************************************/

/* Following DEFINE signalizes the completion of definition                   */
/* of data structs for component: .....................APP_LEVERSELECTION_EVB */
#define _APP_LEVERSELECTION_EVB_TYPE_DEF_




/******************************************************************************
 * BEGIN: declaration of global C functions defined by class APP_LEVERSELECTION_EVB
 ******************************************************************************/
extern struct T_LEVEROUT_EVB * APP_LEVERSELECTION_EVB_APP_LeverSelect (
               struct APP_LEVERSELECTION_EVB * self,
   /* IN    */ boolean                         IN_ParkSwitch,
   /* IN    */ boolean                         IN_ReverseSwitch,
   /* IN    */ boolean                         IN_NeutralSwitch,
   /* IN    */ boolean                         IN_DriveSwitch,
   /* IN    */ boolean                         IN_SportSwitch,
   /* IN    */ boolean                         IN_ManualSwitch,
   /* IN    */ boolean                         IN_PlusSwitch,
   /* IN    */ boolean                         IN_MinusSwitch,
   /* IN    */ uint16                          IN_SteeringWheel
   );



#endif /* _ASD_APP_LEVERSELECTION_EVB_H_ */
