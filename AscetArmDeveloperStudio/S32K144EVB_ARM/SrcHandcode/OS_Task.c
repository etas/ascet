#include "HA_Types.h"
#include "OS_Task.h"
#include "OS_Scheduler.h"
#include "HA_ADC.h"
#include "S32K144.h"


extern void ASCTask1ms(void);
extern void ASCTask5ms(void);
extern void ASCTask10ms(void);
extern void ASCTask100ms(void);
extern void esdl_StartupHook(void);
extern void HA_GPIOInit ();
extern void HA_SetupClocks();
extern void HA_FTMInit();
extern void HA_NVICInit();
extern void HA_LPIT0Init();
extern void HA_FTMStart();
extern void HA_AdcStart();

/* Task containers */
void OS_TaskInit(void)
{
	  HA_GPIOInit ();			/* Initialise ports */
	  HA_SetupClocks();			/* Setup the system clocks */
	  HA_InitADC();				/* Initialise the A to D converters */
	  HA_FTMInit();				/* Initialise the FTM */
	  HA_NVICInit();       	    /* Enable desired interrupts and priorities */
	  HA_LPIT0Init();           /* Initialise OS tick  */
	  esdl_StartupHook();		/* ASCET init task */
	  HA_FTMStart();			/* Start the FTM timers */
}

void OS_Task1ms(void)
{
	HA_AdcStart();				/* Gather ADC data, and kick next conversion */
	ASCTask1ms();				/* Call ASCET 1ms code */
}

void OS_Task5ms(void)
{
	ASCTask5ms();				/* Call ASCET 5ms code */
}

void OS_Task10ms(void)
{
	ASCTask10ms();				/* Call ASCET 10ms code */
}

void OS_Task100ms(void)
{
	ASCTask100ms();				/* Call ASCET 100ms code */
}

void OS_Task1s(void)
{
}


