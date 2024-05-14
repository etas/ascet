#ifndef ESDL_DELTATIMEDEFS_H
#define ESDL_DELTATIMEDEFS_H

/********************************************************************************
 * DO NOT EDIT!
 * AUTOMATICALLY GENERATED
 * DESCRIPTION:
 *   Definitions for delta time calculation
 ********************************************************************************/

/**
 * This global variable contains the scaled (according to the used representation formula)
 * deltaT value (the time between to consecutive activations) of the currently running task.
 * The generated code for the ASCET model uses this variable directly to access that value.
 **/
#define ASCET_DELTA_T_SCALED_TYPE float32
extern ASCET_DELTA_T_SCALED_TYPE ASD_DT_SCALED;

/**
 * Macro definition to set the global ASD_DT_SCALED variable
 * The provided rawDt argument is expected to be an expression representing the deltaT in seconds
 * If identity formula is used (default for float32/64 representations), the unit of that calculated value is second.
 **/
#define ASCET_SET_MODEL_DT(rawDt) ASD_DT_SCALED = (rawDt)

#endif /* ESDL_DELTATIMEDEFS_H */
