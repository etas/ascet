/*
** Copyright (c) 2006-2017 Arm Limited (or its affiliates). All rights reserved.
** Use, modification and redistribution of this file is subject to your possession of a
** valid End User License Agreement for the Arm Product of which these examples are part of 
** and your compliance with all applicable terms and conditions of such licence agreement.
*/

#include "scs.h"
#include <stdio.h>
#include <math.h>
#include <arm_acle.h>
#include "S32K144.h"
#include "HA_Types.h"
#include "OS_Scheduler.h"

#define VectorTableOffsetRegister 0xE000ED08
extern unsigned int Image$$VECTORS$$Base;

extern void HA_DisableWatchdog();

/* Enable the FPU if required */
#ifdef __ARM_FP
extern void $Super$$__rt_lib_init(void);

void $Sub$$__rt_lib_init(void)
{
    /* Enable the FPU in both privileged and user modes by setting bits 20-23 to enable CP10 and CP11 */
    SCS.CPACR = SCS.CPACR | (0xF << 20);
    $Super$$__rt_lib_init();
}
#endif


__attribute__((noreturn)) int main(void)
{
	/* Disable the processor watchdog immediately */
	HA_DisableWatchdog();

    /* Processor starts-up in Privileged Thread Mode using Main Stack */
    /* Tell the processor the location of the vector table, obtained from the scatter file */
    *(volatile unsigned int *)(VectorTableOffsetRegister) = (unsigned int) &Image$$VECTORS$$Base;

    OS_Init();

    OS_Scheduler();

}
