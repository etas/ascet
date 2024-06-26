#ifndef PLATFORM_DEFS_H
#define PLATFORM_DEFS_H

/**
 * @file    platform_defs.h
 *
 * @author  ETAS GmbH
 *
 * @date    2017.11.10 10:36:34
 *
 * @brief   Header file containing header platform specific definitions
 *
 * @version 2.0
 *
 **/
#include "esdl_types.h"
#include "esdl_deltaTimeDefs.h"

/**
 * There are two example implementations available for delta time calculation between task activations.
 */
#define ASCET_DELTA_T_STATIC  1
#define ASCET_DELTA_T_DYNAMIC 2

#if (ASCET_DELTA_T_SUPPORT == ASCET_DELTA_T_STATIC)
	/**
	 * 1) First example is using static delta time calculation. That means the time is not measured at all; instead the periods of tasks
	 * found in application model are used. This might be the favorite implementation for operating system configurations,
	 * where arrival time of task activations is well known and predictable.
	 *
	 * How is that working
	 * ===================
	 * ASCET generates task functions with following pattern, if model contains a variable with  @dT annotation.
	 * ____________________________________________
	 * DEF_GLB_DT_MEASURE                      <- here optionally some required extern declaration can be provided
	 *
	 * TASK(myTask)
	 * {
	 *      DEF_TASK_DT_MEASURE;               <- here some additional variables can be declared
	 *      PRE_TASK_DT_MEASURE(10e-3f);       <- here task period is statically provided as macro argument
	 *
	 *      process1();
	 *      process2();
	 *
	 *      POST_TASK_DT_MEASURE;              <- here the original value of global dT variable will be restored
	 *      TerminateTask();
	 * }
	 * ____________________________________________
	 * To activate static delta time calculation, the  pre-processor symbol ASCET_DELTA_T_SUPPORT shall be set to ASCET_DELTA_T_STATIC.
	 *
	 * The code below provides definitions for the macros:
	 *   DEF_GLB_DT_MEASURE   - provides extern declaration for ASD_DT_SCALED variable
	 *   DEF_TASK_DT_MEASURE  - defines a stack variable ASD_dTSaved to save the original value of ASD_DT_SCALED,
	 *                          so it can be restored at the end of the task
	 *   PRE_TASK_DT_MEASURE  - uses the provided task period to set it in ASD_DT_SCALED, for that
	 *                          ASCET_SET_MODEL_DT() macro is used to apply the conversion formula.
	 *                          That macro is generated by ASCET.
	 *   POST_TASK_DT_MEASURE - restores original value of ASD_DT_SCALED
	 **/
	#warning THESE CODE IS FOR EXAMPLE ONLY! DO NOT USE THIS CODE IN ECUS RUNNING IN ANY VEHICLE WITHOUT REVISING IT AGAINST YOUR REQUIREMENTS!

	#define DEF_GLB_DT_MEASURE                  extern ASCET_DELTA_T_SCALED_TYPE ASD_DT_SCALED

	#define DEF_TASK_DT_MEASURE                 ASCET_DELTA_T_SCALED_TYPE ASD_dTSaved = ASD_DT_SCALED

	/* Note: do {...}while(0) idiom is used here for MISRA compliance */
	#define PRE_TASK_DT_MEASURE(TASK_PERIOD)    do { \
	                                                DisableAllInterrupts(); \
	                                                ASCET_SET_MODEL_DT(TASK_PERIOD); \
	                                                EnableAllInterrupts(); \
	                                            } while(0)
	/* Note: do {...}while(0) idiom is used here for MISRA compliance */
	#define POST_TASK_DT_MEASURE                 do { \
	                                                DisableAllInterrupts(); \
	                                                ASD_DT_SCALED = ASD_dTSaved; \
	                                                EnableAllInterrupts(); \
	                                            } while (0)
#endif /* ASCET_DELTA_T_SUPPORT == ASCET_DELTA_T_STATIC */

#if (ASCET_DELTA_T_SUPPORT == ASCET_DELTA_T_DYNAMIC)
	/**
	 * 2) Second example is using delta time calculation by using stop watch time, which is provide by RTA-OSEK API function like GetStopwatch().
	 * For other operating systems or other platform environment a corresponding function should be used to get access to some
	 * free running hardware counter.
	 *
	 * This might be the favorite implementation for operating system configurations, where arrival time of task activations
	 * has considerable jitter.
	 *
	 * How is that working
	 * ===================
	 * ASCET generates task functions with following pattern, if model contains a variable with  @dT annotation
	 * ____________________________________________
	 * DEF_GLB_DT_MEASURE                      <- here optionally some required extern declaration can be provided
	 *
	 * TASK(myTask)
	 * {
	 *      DEF_TASK_DT_MEASURE;               <- here some additional variables can be declared
	 *      PRE_TASK_DT_MEASURE(10e-3f);       <- here task period is statically provided as macro argument
	 *
	 *      process1();
	 *      process2();
	 *
	 *      POST_TASK_DT_MEASURE;              <- here the original value of global dT variable will be restored
	 *      TerminateTask();
	 * }
	 * ____________________________________________
	 * To activate static delta time calculation, the pre-processor symbol ASCET_DELTA_T_SUPPORT shall be set to ASCET_DELTA_T_DYNAMIC.
	 *
	 * The code below provides definitions for the macros:
	 *   DEF_GLB_DT_MEASURE   - provides extern declaration for ASD_DT_SCALED variable
	 *   DEF_TASK_DT_MEASURE  - defines a stack variable ASD_dTSaved to save the original value of ASD_DT_SCALED,
	 *                          so it can be restored at the end of this task
	 *                          defines a static variable ASD_startTime to store the last activation time
	 *                          defines a stack variable ASD_curTime to store the current activation time
	 *   PRE_TASK_DT_MEASURE  - uses GetStopwatch() API to get the current tick and calculates the delta.
	 *                          exchange the call to GetStopwatch() if your are not using RTA-OSEK
	 *                          exchange OSMAXALLOWEDVALUE to the define the max value, where your counter will overflow
	 *
	 *                          ASCET_SET_MODEL_DT() macro is used to apply the conversion formula and store that value in
	 *                          ASD_DT_SCALED. That macro is generated by ASCET
	 *   POST_TASK_DT_MEASURE - restores original value of ASD_DT_SCALED
	 **/
	#warning THESE CODE IS FOR EXAMPLE ONLY! DO NOT USE THIS CODE IN ECUS RUNNING IN ANY VEHICLE WITHOUT REVISING IT AGAINST YOUR REQUIREMENTS!

	#define DEF_GLB_DT_MEASURE                  extern ASCET_DELTA_T_SCALED_TYPE ASD_DT_SCALED

	#define DEF_TASK_DT_MEASURE                 static TickType ASD_startTime = 0; \
	                                            TickType ASD_curTime; \
	                                            TickType ASD_deltaTicks; \
	                                            ASCET_DELTA_T_SCALED_TYPE ASD_dTSaved

	/* Note: do {...}while(0) idiom is used here for MISRA compliance */
	#define PRE_TASK_DT_MEASURE(TASK_PERIOD)    do { \
	                                                ASD_dTSaved = ASD_DT_SCALED; \
	                                                ASD_curTime = GetStopwatch(); \
	                                                ASD_deltaTicks = (TickType)((ASD_curTime > ASD_startTime) ? \
	                                                     (ASD_curTime - ASD_startTime) \
	                                                    :(OSMAXALLOWEDVALUE-ASD_startTime+ASD_curTime)); \
	                                                DisableAllInterrupts(); \
	                                                /* convert ticks to seconds and pass it to ASCET_SET_MODEL_DT */ \
	                                                /* assumption is that OSTICKDURATION is expressed in nanoseconds */ \
	                                                ASCET_SET_MODEL_DT(OSTICKDURATION * ASD_deltaTicks/1.0e9); \
	                                                EnableAllInterrupts(); \
	                                                ASD_startTime = ASD_curTime; \
	                                            } while(0)

	/* Note: do {...}while(0) idiom is used here for MISRA compliance */
	#define POST_TASK_DT_MEASURE                do { \
	                                                DisableAllInterrupts(); \
	                                                ASD_DT_SCALED = ASD_dTSaved; \
	                                                EnableAllInterrupts(); \
	                                            } while(0)
#endif /* ASCET_DELTA_T_SUPPORT == ASCET_DELTA_T_DYNAMIC */

#endif /* PLATFORM_DEFS_H */
