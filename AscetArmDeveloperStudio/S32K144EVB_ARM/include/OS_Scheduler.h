#ifndef OS_SCHEDULER_H_
#define OS_SCHEDULER_H_

/* Defines for very simple scheduler */
/* The following assumes a 2000Hz call rate (500us) */
#define HA_OS1MSTHRESH		2
#define HA_OS5MSTHRESH		10
#define HA_OS10MSTHRESH		20
#define HA_OS100MSTHRESH	200
#define HA_OS1STHRESH		2000

#define HA_OS1MSPHASE		0
#define HA_OS5MSPHASE		1
#define HA_OS10MSPHASE		1
#define HA_OS100MSPHASE		1
#define HA_OS1SPHASE		1

/* OS Functions */
extern void OS_IsrHandler(void);
extern void OS_Init(void);
extern void OS_Scheduler(void);
extern void OS_Shutdown(void);
extern void OS_RequestStop(void);

#endif /* OS_SCHEDULER_H_ */
