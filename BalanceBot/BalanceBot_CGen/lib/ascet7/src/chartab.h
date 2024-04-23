#ifndef _ASD_CHARTAB_H_
#define _ASD_CHARTAB_H_



/*-----------------------------------------------------------------------------
 *    Enumeration Type Definitions
 *----------------------------------------------------------------------------*/

/* definition of Enumeration type: "control_EModes" */
typedef enum control_EModes {
   control_EModes_STOP_BALANCING = 0U, 
   control_EModes_GO_FORWARD = 1U, 
   control_EModes_TURN_RIGHT = 2U, 
   control_EModes_TURN_LEFT = 3U, 
   control_EModes_GO_BACKWARD = 4U, 
   control_EModes_STOP = 5U, 
   control_EModes_BUZZER_ON = 6U, 
   control_EModes_BUZZER_OFF = 7U, 
   control_EModes_STOP_TURNING = 8U, 
   control_EModes_INC_KPSPEED = 9U, 
   control_EModes_DEC_KPSPEED = 10U, 
   control_EModes_INC_KPANGLE = 11U, 
   control_EModes_DEC_KPANGLE = 12U, 
   control_EModes_INC_KISPEED = 13U, 
   control_EModes_DEC_KISPEED = 14U, 
   control_EModes_INC_ZEROANGLE = 15U, 
   control_EModes_DEC_ZEROANGLE = 16U, 
   control_EModes_OBSTACLE_AVOIDANCE = 17U, 
   control_EModes_OPENLAB_MODE = 18U, 
   control_EModes_INC_KIANGLE = 19U, 
   control_EModes_DEC_KIANGLE = 20U
} control_EModes;


/* definition of State Machine Enumeration type: "control_RemoteCommands_enum" (derived from class "control_RemoteCommands") */
/* typedef not provided, base type "uint8" used instead (code generation option "Generation of enums" not set to "Enumeration") */

#endif /* _ASD_CHARTAB_H_ */
