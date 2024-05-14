/*
** Copyright (c) 2006-2017 Arm Limited (or its affiliates). All rights reserved.
** Use(void){while(1);} modification and redistribution of this file is subject to your possession of a
** valid End User License Agreement for the Arm Product of which these examples are part of 
** and your compliance with all applicable terms and conditions of such licence agreement.
*/

/* This file contains the default exception Handlers and vector table.
All exceptions are handled in Handler mode.  Processor state is automatically
pushed onto the stack when an exception occurs, and popped from the stack at
the end of the Handler, */


/* Exception Handlers */
/* Marking as __attribute__((interrupt)) avoids them being accidentally called from elsewhere */

__attribute__((interrupt)) void NMIException(void)
{   while(1); }

__attribute__((interrupt)) void HardFaultException(void)
{   while(1); }

__attribute__((interrupt)) void MemManageException(void)
{   while(1); }

__attribute__((interrupt)) void BusFaultException(void)
{   while(1); }

__attribute__((interrupt)) void UsageFaultException(void)
{   while(1); }

__attribute__((interrupt)) void DebugMonitor(void)
{   while(1); }

__attribute__((interrupt)) void SVCHandler(void)
{   while(1); }

__attribute__((interrupt)) void PendSVC(void)
{   while(1); }

__attribute__((interrupt)) void SysTickHandler(void)
{  while(1); }

__attribute__((interrupt)) void InterruptHandler(void)
{   while(1); }

__attribute__((interrupt)) void DMA0_IRQHandler(void){while(1);}
__attribute__((interrupt)) void DMA1_IRQHandler(void){while(1);}                                 /* DMA channel 1 transfer complete*/
__attribute__((interrupt)) void DMA2_IRQHandler(void){while(1);}                                 /* DMA channel 2 transfer complete*/
__attribute__((interrupt)) void DMA3_IRQHandler(void){while(1);}                                 /* DMA channel 3 transfer complete*/
__attribute__((interrupt)) void DMA4_IRQHandler(void){while(1);}                                 /* DMA channel 4 transfer complete*/
__attribute__((interrupt)) void DMA5_IRQHandler(void){while(1);}                                 /* DMA channel 5 transfer complete*/
__attribute__((interrupt)) void DMA6_IRQHandler(void){while(1);}                                 /* DMA channel 6 transfer complete*/
__attribute__((interrupt)) void DMA7_IRQHandler(void){while(1);}                                 /* DMA channel 7 transfer complete*/
__attribute__((interrupt)) void DMA8_IRQHandler(void){while(1);}                                 /* DMA channel 8 transfer complete*/
__attribute__((interrupt)) void DMA9_IRQHandler(void){while(1);}                                 /* DMA channel 9 transfer complete*/
__attribute__((interrupt)) void DMA10_IRQHandler(void){while(1);}                                /* DMA channel 10 transfer complete*/
__attribute__((interrupt)) void DMA11_IRQHandler(void){while(1);}                                /* DMA channel 11 transfer complete*/
__attribute__((interrupt)) void DMA12_IRQHandler(void){while(1);}                                /* DMA channel 12 transfer complete*/
__attribute__((interrupt)) void DMA13_IRQHandler(void){while(1);}                                /* DMA channel 13 transfer complete*/
__attribute__((interrupt)) void DMA14_IRQHandler(void){while(1);}                                /* DMA channel 14 transfer complete*/
__attribute__((interrupt)) void DMA15_IRQHandler(void){while(1);}                                /* DMA channel 15 transfer complete*/
__attribute__((interrupt)) void DMA_Error_IRQHandler(void){while(1);}                            /* DMA error interrupt channels 0-15*/
__attribute__((interrupt)) void MCM_IRQHandler(void){while(1);}                                  /* FPU sources*/
__attribute__((interrupt)) void FTFC_IRQHandler(void){while(1);}                                 /* FTFC Command complete*/
__attribute__((interrupt)) void Read_Collision_IRQHandler(void){while(1);}                       /* FTFC Read collision*/
__attribute__((interrupt)) void LVD_LVW_IRQHandler(void){while(1);}                              /* PMC Low voltage detect interrupt*/
__attribute__((interrupt)) void FTFC_Fault_IRQHandler(void){while(1);}                           /* FTFC Double bit fault detect*/
__attribute__((interrupt)) void RCM_IRQHandler(void){while(1);}                                  /* RCM Asynchronous Interrupt*/
__attribute__((interrupt)) void LPI2C0_Master_IRQHandler(void){while(1);}                        /* LPI2C0 Master Interrupt*/
__attribute__((interrupt)) void LPI2C0_Slave_IRQHandler(void){while(1);}                         /* LPI2C0 Slave Interrupt*/
__attribute__((interrupt)) void LPSPI0_IRQHandler(void){while(1);}                               /* LPSPI0 Interrupt*/
__attribute__((interrupt)) void LPSPI1_IRQHandler(void){while(1);}                               /* LPSPI1 Interrupt*/
__attribute__((interrupt)) void LPSPI2_IRQHandler(void){while(1);}                               /* LPSPI2 Interrupt*/
__attribute__((interrupt)) void Reserved45_IRQHandler(void){while(1);}                           /* Reserved Interrupt 45*/
__attribute__((interrupt)) void Reserved46_IRQHandler(void){while(1);}                           /* Reserved Interrupt 46*/
__attribute__((interrupt)) void LPUART0_RxTx_IRQHandler(void){while(1);}                         /* LPUART0 Transmit / Receive Interrupt*/
__attribute__((interrupt)) void Reserved48_IRQHandler(void){while(1);}                           /* Reserved Interrupt 48*/
__attribute__((interrupt)) void LPUART1_RxTx_IRQHandler(void){while(1);}                         /* LPUART1 Transmit / Receive  Interrupt*/
__attribute__((interrupt)) void Reserved50_IRQHandler(void){while(1);}                           /* Reserved Interrupt 50*/
__attribute__((interrupt)) void LPUART2_RxTx_IRQHandler(void){while(1);}                         /* LPUART2 Transmit / Receive  Interrupt*/
__attribute__((interrupt)) void Reserved52_IRQHandler(void){while(1);}                           /* Reserved Interrupt 52*/
__attribute__((interrupt)) void Reserved53_IRQHandler(void){while(1);}                           /* Reserved Interrupt 53*/
__attribute__((interrupt)) void Reserved54_IRQHandler(void){while(1);}                           /* Reserved Interrupt 54*/
__attribute__((interrupt)) void ADC0_IRQHandler(void){while(1);}                                 /* ADC0 interrupt request.*/
__attribute__((interrupt)) void ADC1_IRQHandler(void){while(1);}                                 /* ADC1 interrupt request.*/
__attribute__((interrupt)) void CMP0_IRQHandler(void){while(1);}                                 /* CMP0 interrupt request*/
__attribute__((interrupt)) void Reserved58_IRQHandler(void){while(1);}                           /* Reserved Interrupt 58*/
__attribute__((interrupt)) void Reserved59_IRQHandler(void){while(1);}                           /* Reserved Interrupt 59*/
__attribute__((interrupt)) void ERM_single_fault_IRQHandler(void){while(1);}                     /* ERM single bit error correction*/
__attribute__((interrupt)) void ERM_double_fault_IRQHandler(void){while(1);}                     /* ERM double bit error non-correctable*/
__attribute__((interrupt)) void RTC_IRQHandler(void){while(1);}                                  /* RTC alarm interrupt*/
__attribute__((interrupt)) void RTC_Seconds_IRQHandler(void){while(1);}                          /* RTC seconds interrupt*/
__attribute__((interrupt)) void LPIT0_Ch1_IRQHandler(void){while(1);}                            /* LPIT0 channel 1 overflow interrupt*/
__attribute__((interrupt)) void LPIT0_Ch2_IRQHandler(void){while(1);}                            /* LPIT0 channel 2 overflow interrupt*/
__attribute__((interrupt)) void LPIT0_Ch3_IRQHandler(void){while(1);}                            /* LPIT0 channel 3 overflow interrupt*/
__attribute__((interrupt)) void PDB0_IRQHandler(void){while(1);}                                 /* PDB0 interrupt*/
__attribute__((interrupt)) void Reserved69_IRQHandler(void){while(1);}                           /* Reserved Interrupt 69*/
__attribute__((interrupt)) void Reserved70_IRQHandler(void){while(1);}                           /* Reserved Interrupt 70*/
__attribute__((interrupt)) void Reserved71_IRQHandler(void){while(1);}                           /* Reserved Interrupt 71*/
__attribute__((interrupt)) void Reserved72_IRQHandler(void){while(1);}                           /* Reserved Interrupt 72*/
__attribute__((interrupt)) void SCG_IRQHandler(void){while(1);}                                  /* SCG bus interrupt request*/
__attribute__((interrupt)) void LPTMR0_IRQHandler(void){while(1);}                               /* LPTIMER interrupt request*/
__attribute__((interrupt)) void PORTA_IRQHandler(void){while(1);}                                /* Port A pin detect interrupt*/
__attribute__((interrupt)) void PORTB_IRQHandler(void){while(1);}                                /* Port B pin detect interrupt*/
__attribute__((interrupt)) void PORTC_IRQHandler(void){while(1);}                                /* Port C pin detect interrupt*/
__attribute__((interrupt)) void PORTD_IRQHandler(void){while(1);}                                /* Port D pin detect interrupt*/
__attribute__((interrupt)) void PORTE_IRQHandler(void){while(1);}                                /* Port E pin detect interrupt*/
__attribute__((interrupt)) void SWI_IRQHandler(void){while(1);}                                  /* Software interrupt*/
__attribute__((interrupt)) void Reserved81_IRQHandler(void){while(1);}                           /* Reserved Interrupt 81*/
__attribute__((interrupt)) void Reserved82_IRQHandler(void){while(1);}                           /* Reserved Interrupt 82*/
__attribute__((interrupt)) void Reserved83_IRQHandler(void){while(1);}                           /* Reserved Interrupt 83*/
__attribute__((interrupt)) void PDB1_IRQHandler(void){while(1);}                                 /* PDB1 interrupt*/
__attribute__((interrupt)) void FLEXIO_IRQHandler(void){while(1);}                               /* FlexIO Interrupt*/
__attribute__((interrupt)) void Reserved86_IRQHandler(void){while(1);}                           /* Reserved Interrupt 86*/
__attribute__((interrupt)) void Reserved87_IRQHandler(void){while(1);}                           /* Reserved Interrupt 87*/
__attribute__((interrupt)) void Reserved88_IRQHandler(void){while(1);}                           /* Reserved Interrupt 88*/
__attribute__((interrupt)) void Reserved89_IRQHandler(void){while(1);}                           /* Reserved Interrupt 89*/
__attribute__((interrupt)) void Reserved90_IRQHandler(void){while(1);}                           /* Reserved Interrupt 90*/
__attribute__((interrupt)) void Reserved91_IRQHandler(void){while(1);}                           /* Reserved Interrupt 91*/
__attribute__((interrupt)) void Reserved92_IRQHandler(void){while(1);}                           /* Reserved Interrupt 92*/
__attribute__((interrupt)) void Reserved93_IRQHandler(void){while(1);}                           /* Reserved Interrupt 93*/
__attribute__((interrupt)) void CAN0_ORed_IRQHandler(void){while(1);}                            /* CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
__attribute__((interrupt)) void CAN0_Error_IRQHandler(void){while(1);}                           /* CAN0 Interrupt indicating that errors were detected on the CAN bus*/
__attribute__((interrupt)) void CAN0_Wake_Up_IRQHandler(void){while(1);}                         /* CAN0 Interrupt asserted when Pretended Networking operation is enabled(void){while(1);} and a valid message matches the selected filter criteria during Low Power mode*/
__attribute__((interrupt)) void CAN0_ORed_0_15_MB_IRQHandler(void){while(1);}                    /* CAN0 OR'ed Message buffer (0-15)*/
__attribute__((interrupt)) void CAN0_ORed_16_31_MB_IRQHandler(void){while(1);}                   /* CAN0 OR'ed Message buffer (16-31)*/
__attribute__((interrupt)) void Reserved99_IRQHandler(void){while(1);}                           /* Reserved Interrupt 99*/
__attribute__((interrupt)) void Reserved100_IRQHandler(void){while(1);}                          /* Reserved Interrupt 100*/
__attribute__((interrupt)) void CAN1_ORed_IRQHandler(void){while(1);}                            /* CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
__attribute__((interrupt)) void CAN1_Error_IRQHandler(void){while(1);}                           /* CAN1 Interrupt indicating that errors were detected on the CAN bus*/
__attribute__((interrupt)) void Reserved103_IRQHandler(void){while(1);}                          /* Reserved Interrupt 103*/
__attribute__((interrupt)) void CAN1_ORed_0_15_MB_IRQHandler(void){while(1);}                    /* CAN1 OR'ed Interrupt for Message buffer (0-15)*/
__attribute__((interrupt)) void Reserved105_IRQHandler(void){while(1);}                          /* Reserved Interrupt 105*/
__attribute__((interrupt)) void Reserved106_IRQHandler(void){while(1);}                          /* Reserved Interrupt 106*/
__attribute__((interrupt)) void Reserved107_IRQHandler(void){while(1);}                          /* Reserved Interrupt 107*/
__attribute__((interrupt)) void CAN2_ORed_IRQHandler(void){while(1);}                            /* CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
__attribute__((interrupt)) void CAN2_Error_IRQHandler(void){while(1);}                           /* CAN2 Interrupt indicating that errors were detected on the CAN bus*/
__attribute__((interrupt)) void Reserved110_IRQHandler(void){while(1);}                          /* Reserved Interrupt 110*/
__attribute__((interrupt)) void CAN2_ORed_0_15_MB_IRQHandler(void){while(1);}                    /* CAN2 OR'ed Message buffer (0-15)*/
__attribute__((interrupt)) void Reserved112_IRQHandler(void){while(1);}                          /* Reserved Interrupt 112*/
__attribute__((interrupt)) void Reserved113_IRQHandler(void){while(1);}                          /* Reserved Interrupt 113*/
__attribute__((interrupt)) void Reserved114_IRQHandler(void){while(1);}                          /* Reserved Interrupt 114*/
__attribute__((interrupt)) void FTM0_Ch0_Ch1_IRQHandler(void){while(1);}                         /* FTM0 Channel 0 and 1 interrupt*/
__attribute__((interrupt)) void FTM0_Ch2_Ch3_IRQHandler(void){while(1);}                         /* FTM0 Channel 2 and 3 interrupt*/
__attribute__((interrupt)) void FTM0_Ch4_Ch5_IRQHandler(void){while(1);}                         /* FTM0 Channel 4 and 5 interrupt*/
__attribute__((interrupt)) void FTM0_Ch6_Ch7_IRQHandler(void){while(1);}                         /* FTM0 Channel 6 and 7 interrupt*/
__attribute__((interrupt)) void FTM0_Fault_IRQHandler(void){while(1);}                           /* FTM0 Fault interrupt*/
__attribute__((interrupt)) void FTM0_Ovf_Reload_IRQHandler(void){while(1);}                      /* FTM0 Counter overflow and Reload interrupt*/
__attribute__((interrupt)) void FTM1_Ch0_Ch1_IRQHandler(void){while(1);}                         /* FTM1 Channel 0 and 1 interrupt*/
__attribute__((interrupt)) void FTM1_Ch2_Ch3_IRQHandler(void){while(1);}                         /* FTM1 Channel 2 and 3 interrupt*/
__attribute__((interrupt)) void FTM1_Ch4_Ch5_IRQHandler(void){while(1);}                         /* FTM1 Channel 4 and 5 interrupt*/
__attribute__((interrupt)) void FTM1_Ch6_Ch7_IRQHandler(void){while(1);}                         /* FTM1 Channel 6 and 7 interrupt*/
__attribute__((interrupt)) void FTM1_Fault_IRQHandler(void){while(1);}                           /* FTM1 Fault interrupt*/
__attribute__((interrupt)) void FTM1_Ovf_Reload_IRQHandler(void){while(1);}                      /* FTM1 Counter overflow and Reload interrupt*/
__attribute__((interrupt)) void FTM2_Ch0_Ch1_IRQHandler(void){while(1);}                         /* FTM2 Channel 0 and 1 interrupt*/
__attribute__((interrupt)) void FTM2_Ch2_Ch3_IRQHandler(void){while(1);}                         /* FTM2 Channel 2 and 3 interrupt*/
__attribute__((interrupt)) void FTM2_Ch4_Ch5_IRQHandler(void){while(1);}                         /* FTM2 Channel 4 and 5 interrupt*/
__attribute__((interrupt)) void FTM2_Ch6_Ch7_IRQHandler(void){while(1);}                         /* FTM2 Channel 6 and 7 interrupt*/
__attribute__((interrupt)) void FTM2_Fault_IRQHandler(void){while(1);}                           /* FTM2 Fault interrupt*/
__attribute__((interrupt)) void FTM2_Ovf_Reload_IRQHandler(void){while(1);}                      /* FTM2 Counter overflow and Reload interrupt*/
__attribute__((interrupt)) void FTM3_Fault_IRQHandler(void){while(1);}                           /* FTM3 Fault interrupt*/
__attribute__((interrupt)) void DefaultISR(void){while(1);}                                      /* 139*/

/* Already defined ISRs */
extern __attribute__((interrupt)) void FTM3_Ch0_Ch1_IRQHandler(void);                         /* FTM3 Channel 0 and 1 interrupt*/
extern __attribute__((interrupt)) void FTM3_Ch2_Ch3_IRQHandler(void);                         /* FTM3 Channel 2 and 3 interrupt*/
extern __attribute__((interrupt)) void FTM3_Ch4_Ch5_IRQHandler(void);                         /* FTM3 Channel 4 and 5 interrupt*/
extern __attribute__((interrupt)) void FTM3_Ch6_Ch7_IRQHandler(void);                         /* FTM3 Channel 6 and 7 interrupt*/
extern __attribute__((interrupt)) void FTM3_Ovf_Reload_IRQHandler(void);                      /* FTM3 Counter overflow and Reload interrupt*/
extern __attribute__((interrupt)) void LPIT0_Ch0_IRQHandler(void);                           /* LPIT0 channel 0 overflow interrupt*/
extern __attribute__((interrupt)) void WDOG_EWM_IRQHandler(void);                             /* Single interrupt vector for WDOG and EWM*/


/* typedef for the function pointers in the vector table */
typedef void(* const ExecFuncPtr)(void) __attribute__((interrupt));

/* Linker-generated Stack Base address */
#ifdef TWO_REGION
extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Limit;     /* for Two Region model */
#else
extern unsigned int Image$$ARM_LIB_STACKHEAP$$ZI$$Limit; /* for (default) One Region model */
#endif

/* Entry point for C run-time initialization */
extern int __main(void);


/* Vector table
Create a named ELF section for the vector table that can be placed in a scatter file.
The first two entries are:
    Initial SP = |Image$$ARM_LIB_STACKHEAP$$ZI$$Limit| for (default) One Region model
              or |Image$$ARM_LIB_STACK$$ZI$$Limit|     for Two Region model
    Initial PC= &__main (with LSB set to indicate Thumb)
*/

ExecFuncPtr vector_table[] __attribute__((section("vectors"))) = {
     /* Configure Initial Stack Pointer using linker-generated symbol */
#ifdef TWO_REGION
    #pragma import(__use_two_region_memory)
    (ExecFuncPtr)&Image$$ARM_LIB_STACK$$ZI$$Limit,
#else /* (default) One Region model */
    (ExecFuncPtr)&Image$$ARM_LIB_STACKHEAP$$ZI$$Limit,
#endif
    (ExecFuncPtr)__main, /* Initial PC, set to entry point  */
    NMIException,
    HardFaultException,
    MemManageException,
    BusFaultException,
    UsageFaultException,
    0, 0, 0, 0,             /* Reserved */
    SVCHandler,
    DebugMonitor,
    0,                      /* Reserved */
    PendSVC,
    SysTickHandler,
     DMA0_IRQHandler,                                 /* DMA channel 0 transfer complete*/
     DMA1_IRQHandler,                                 /* DMA channel 1 transfer complete*/
     DMA2_IRQHandler,                                 /* DMA channel 2 transfer complete*/
     DMA3_IRQHandler,                                 /* DMA channel 3 transfer complete*/
     DMA4_IRQHandler,                                 /* DMA channel 4 transfer complete*/
     DMA5_IRQHandler,                                 /* DMA channel 5 transfer complete*/
     DMA6_IRQHandler,                                 /* DMA channel 6 transfer complete*/
     DMA7_IRQHandler,                                 /* DMA channel 7 transfer complete*/
     DMA8_IRQHandler,                                 /* DMA channel 8 transfer complete*/
     DMA9_IRQHandler,                                 /* DMA channel 9 transfer complete*/
     DMA10_IRQHandler,                                /* DMA channel 10 transfer complete*/
     DMA11_IRQHandler,                                /* DMA channel 11 transfer complete*/
     DMA12_IRQHandler,                                /* DMA channel 12 transfer complete*/
     DMA13_IRQHandler,                                /* DMA channel 13 transfer complete*/
     DMA14_IRQHandler,                                /* DMA channel 14 transfer complete*/
     DMA15_IRQHandler,                                /* DMA channel 15 transfer complete*/
     DMA_Error_IRQHandler,                            /* DMA error interrupt channels 0-15*/
     MCM_IRQHandler,                                  /* FPU sources*/
     FTFC_IRQHandler,                                 /* FTFC Command complete*/
     Read_Collision_IRQHandler,                       /* FTFC Read collision*/
     LVD_LVW_IRQHandler,                              /* PMC Low voltage detect interrupt*/
     FTFC_Fault_IRQHandler,                           /* FTFC Double bit fault detect*/
     WDOG_EWM_IRQHandler,                             /* Single interrupt vector for WDOG and EWM*/
     RCM_IRQHandler,                                  /* RCM Asynchronous Interrupt*/
     LPI2C0_Master_IRQHandler,                        /* LPI2C0 Master Interrupt*/
     LPI2C0_Slave_IRQHandler,                         /* LPI2C0 Slave Interrupt*/
     LPSPI0_IRQHandler,                               /* LPSPI0 Interrupt*/
     LPSPI1_IRQHandler,                               /* LPSPI1 Interrupt*/
     LPSPI2_IRQHandler,                               /* LPSPI2 Interrupt*/
     Reserved45_IRQHandler,                           /* Reserved Interrupt 45*/
     Reserved46_IRQHandler,                           /* Reserved Interrupt 46*/
     LPUART0_RxTx_IRQHandler,                         /* LPUART0 Transmit / Receive Interrupt*/
     Reserved48_IRQHandler,                           /* Reserved Interrupt 48*/
     LPUART1_RxTx_IRQHandler,                         /* LPUART1 Transmit / Receive  Interrupt*/
     Reserved50_IRQHandler,                           /* Reserved Interrupt 50*/
     LPUART2_RxTx_IRQHandler,                         /* LPUART2 Transmit / Receive  Interrupt*/
     Reserved52_IRQHandler,                           /* Reserved Interrupt 52*/
     Reserved53_IRQHandler,                           /* Reserved Interrupt 53*/
     Reserved54_IRQHandler,                           /* Reserved Interrupt 54*/
     ADC0_IRQHandler,                                 /* ADC0 interrupt request.*/
     ADC1_IRQHandler,                                 /* ADC1 interrupt request.*/
     CMP0_IRQHandler,                                 /* CMP0 interrupt request*/
     Reserved58_IRQHandler,                           /* Reserved Interrupt 58*/
     Reserved59_IRQHandler,                           /* Reserved Interrupt 59*/
     ERM_single_fault_IRQHandler,                     /* ERM single bit error correction*/
     ERM_double_fault_IRQHandler,                     /* ERM double bit error non-correctable*/
     RTC_IRQHandler,                                  /* RTC alarm interrupt*/
     RTC_Seconds_IRQHandler,                          /* RTC seconds interrupt*/
     LPIT0_Ch0_IRQHandler,                            /* LPIT0 channel 0 overflow interrupt*/
     LPIT0_Ch1_IRQHandler,                            /* LPIT0 channel 1 overflow interrupt*/
     LPIT0_Ch2_IRQHandler,                            /* LPIT0 channel 2 overflow interrupt*/
     LPIT0_Ch3_IRQHandler,                            /* LPIT0 channel 3 overflow interrupt*/
     PDB0_IRQHandler,                                 /* PDB0 interrupt*/
     Reserved69_IRQHandler,                           /* Reserved Interrupt 69*/
     Reserved70_IRQHandler,                           /* Reserved Interrupt 70*/
     Reserved71_IRQHandler,                           /* Reserved Interrupt 71*/
     Reserved72_IRQHandler,                           /* Reserved Interrupt 72*/
     SCG_IRQHandler,                                  /* SCG bus interrupt request*/
     LPTMR0_IRQHandler,                               /* LPTIMER interrupt request*/
     PORTA_IRQHandler,                                /* Port A pin detect interrupt*/
     PORTB_IRQHandler,                                /* Port B pin detect interrupt*/
     PORTC_IRQHandler,                                /* Port C pin detect interrupt*/
     PORTD_IRQHandler,                                /* Port D pin detect interrupt*/
     PORTE_IRQHandler,                                /* Port E pin detect interrupt*/
     SWI_IRQHandler,                                  /* Software interrupt*/
     Reserved81_IRQHandler,                           /* Reserved Interrupt 81*/
     Reserved82_IRQHandler,                           /* Reserved Interrupt 82*/
     Reserved83_IRQHandler,                           /* Reserved Interrupt 83*/
     PDB1_IRQHandler,                                 /* PDB1 interrupt*/
     FLEXIO_IRQHandler,                               /* FlexIO Interrupt*/
     Reserved86_IRQHandler,                           /* Reserved Interrupt 86*/
     Reserved87_IRQHandler,                           /* Reserved Interrupt 87*/
     Reserved88_IRQHandler,                           /* Reserved Interrupt 88*/
     Reserved89_IRQHandler,                           /* Reserved Interrupt 89*/
     Reserved90_IRQHandler,                           /* Reserved Interrupt 90*/
     Reserved91_IRQHandler,                           /* Reserved Interrupt 91*/
     Reserved92_IRQHandler,                           /* Reserved Interrupt 92*/
     Reserved93_IRQHandler,                           /* Reserved Interrupt 93*/
     CAN0_ORed_IRQHandler,                            /* CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
     CAN0_Error_IRQHandler,                           /* CAN0 Interrupt indicating that errors were detected on the CAN bus*/
     CAN0_Wake_Up_IRQHandler,                         /* CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode*/
     CAN0_ORed_0_15_MB_IRQHandler,                    /* CAN0 OR'ed Message buffer (0-15)*/
     CAN0_ORed_16_31_MB_IRQHandler,                   /* CAN0 OR'ed Message buffer (16-31)*/
     Reserved99_IRQHandler,                           /* Reserved Interrupt 99*/
     Reserved100_IRQHandler,                          /* Reserved Interrupt 100*/
     CAN1_ORed_IRQHandler,                            /* CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
     CAN1_Error_IRQHandler,                           /* CAN1 Interrupt indicating that errors were detected on the CAN bus*/
     Reserved103_IRQHandler,                          /* Reserved Interrupt 103*/
     CAN1_ORed_0_15_MB_IRQHandler,                    /* CAN1 OR'ed Interrupt for Message buffer (0-15)*/
     Reserved105_IRQHandler,                          /* Reserved Interrupt 105*/
     Reserved106_IRQHandler,                          /* Reserved Interrupt 106*/
     Reserved107_IRQHandler,                          /* Reserved Interrupt 107*/
     CAN2_ORed_IRQHandler,                            /* CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning]*/
     CAN2_Error_IRQHandler,                           /* CAN2 Interrupt indicating that errors were detected on the CAN bus*/
     Reserved110_IRQHandler,                          /* Reserved Interrupt 110*/
     CAN2_ORed_0_15_MB_IRQHandler,                    /* CAN2 OR'ed Message buffer (0-15)*/
     Reserved112_IRQHandler,                          /* Reserved Interrupt 112*/
     Reserved113_IRQHandler,                          /* Reserved Interrupt 113*/
     Reserved114_IRQHandler,                          /* Reserved Interrupt 114*/
     FTM0_Ch0_Ch1_IRQHandler,                         /* FTM0 Channel 0 and 1 interrupt*/
     FTM0_Ch2_Ch3_IRQHandler,                         /* FTM0 Channel 2 and 3 interrupt*/
     FTM0_Ch4_Ch5_IRQHandler,                         /* FTM0 Channel 4 and 5 interrupt*/
     FTM0_Ch6_Ch7_IRQHandler,                         /* FTM0 Channel 6 and 7 interrupt*/
     FTM0_Fault_IRQHandler,                           /* FTM0 Fault interrupt*/
     FTM0_Ovf_Reload_IRQHandler,                      /* FTM0 Counter overflow and Reload interrupt*/
     FTM1_Ch0_Ch1_IRQHandler,                         /* FTM1 Channel 0 and 1 interrupt*/
     FTM1_Ch2_Ch3_IRQHandler,                         /* FTM1 Channel 2 and 3 interrupt*/
     FTM1_Ch4_Ch5_IRQHandler,                         /* FTM1 Channel 4 and 5 interrupt*/
     FTM1_Ch6_Ch7_IRQHandler,                         /* FTM1 Channel 6 and 7 interrupt*/
     FTM1_Fault_IRQHandler,                           /* FTM1 Fault interrupt*/
     FTM1_Ovf_Reload_IRQHandler,                      /* FTM1 Counter overflow and Reload interrupt*/
     FTM2_Ch0_Ch1_IRQHandler,                         /* FTM2 Channel 0 and 1 interrupt*/
     FTM2_Ch2_Ch3_IRQHandler,                         /* FTM2 Channel 2 and 3 interrupt*/
     FTM2_Ch4_Ch5_IRQHandler,                         /* FTM2 Channel 4 and 5 interrupt*/
     FTM2_Ch6_Ch7_IRQHandler,                         /* FTM2 Channel 6 and 7 interrupt*/
     FTM2_Fault_IRQHandler,                           /* FTM2 Fault interrupt*/
     FTM2_Ovf_Reload_IRQHandler,                      /* FTM2 Counter overflow and Reload interrupt*/
     FTM3_Ch0_Ch1_IRQHandler,                         /* FTM3 Channel 0 and 1 interrupt*/
     FTM3_Ch2_Ch3_IRQHandler,                         /* FTM3 Channel 2 and 3 interrupt*/
     FTM3_Ch4_Ch5_IRQHandler,                         /* FTM3 Channel 4 and 5 interrupt*/
     FTM3_Ch6_Ch7_IRQHandler,                         /* FTM3 Channel 6 and 7 interrupt*/
     FTM3_Fault_IRQHandler,                           /* FTM3 Fault interrupt*/
     FTM3_Ovf_Reload_IRQHandler,                      /* FTM3 Counter overflow and Reload interrupt*/
     DefaultISR,                                      /* 139*/
     DefaultISR,                                      /* 140*/
     DefaultISR,                                      /* 141*/
     DefaultISR,                                      /* 142*/
     DefaultISR,                                      /* 143*/
     DefaultISR,                                      /* 144*/
     DefaultISR,                                      /* 145*/
     DefaultISR,                                      /* 146*/
     DefaultISR,                                      /* 147*/
     DefaultISR,                                      /* 148*/
     DefaultISR,                                      /* 149*/
     DefaultISR,                                      /* 150*/
     DefaultISR,                                      /* 151*/
     DefaultISR,                                      /* 152*/
     DefaultISR,                                      /* 153*/
     DefaultISR,                                      /* 154*/
     DefaultISR,                                      /* 155*/
     DefaultISR,                                      /* 156*/
     DefaultISR,                                      /* 157*/
     DefaultISR,                                      /* 158*/
     DefaultISR,                                      /* 159*/
     DefaultISR,                                      /* 160*/
     DefaultISR,                                      /* 161*/
     DefaultISR,                                      /* 162*/
     DefaultISR,                                      /* 163*/
     DefaultISR,                                      /* 164*/
     DefaultISR,                                      /* 165*/
     DefaultISR,                                      /* 166*/
     DefaultISR,                                      /* 167*/
     DefaultISR,                                      /* 168*/
     DefaultISR,                                      /* 169*/
     DefaultISR,                                      /* 170*/
     DefaultISR,                                      /* 171*/
     DefaultISR,                                      /* 172*/
     DefaultISR,                                      /* 173*/
     DefaultISR,                                      /* 174*/
     DefaultISR,                                      /* 175*/
     DefaultISR,                                      /* 176*/
     DefaultISR,                                      /* 177*/
     DefaultISR,                                      /* 178*/
     DefaultISR,                                      /* 179*/
     DefaultISR,                                      /* 180*/
     DefaultISR,                                      /* 181*/
     DefaultISR,                                      /* 182*/
     DefaultISR,                                      /* 183*/
     DefaultISR,                                      /* 184*/
     DefaultISR,                                      /* 185*/
     DefaultISR,                                      /* 186*/
     DefaultISR,                                      /* 187*/
     DefaultISR,                                      /* 188*/
     DefaultISR,                                      /* 189*/
     DefaultISR,                                      /* 190*/
     DefaultISR,                                      /* 191*/
     DefaultISR,                                      /* 192*/
     DefaultISR,                                      /* 193*/
     DefaultISR,                                      /* 194*/
     DefaultISR,                                      /* 195*/
     DefaultISR,                                      /* 196*/
     DefaultISR,                                      /* 197*/
     DefaultISR,                                      /* 198*/
     DefaultISR,                                      /* 199*/
     DefaultISR,                                      /* 200*/
     DefaultISR,                                      /* 201*/
     DefaultISR,                                      /* 202*/
     DefaultISR,                                      /* 203*/
     DefaultISR,                                      /* 204*/
     DefaultISR,                                      /* 205*/
     DefaultISR,                                      /* 206*/
     DefaultISR,                                      /* 207*/
     DefaultISR,                                      /* 208*/
     DefaultISR,                                      /* 209*/
     DefaultISR,                                      /* 210*/
     DefaultISR,                                      /* 211*/
     DefaultISR,                                      /* 212*/
     DefaultISR,                                      /* 213*/
     DefaultISR,                                      /* 214*/
     DefaultISR,                                      /* 215*/
     DefaultISR,                                      /* 216*/
     DefaultISR,                                      /* 217*/
     DefaultISR,                                      /* 218*/
     DefaultISR,                                      /* 219*/
     DefaultISR,                                      /* 220*/
     DefaultISR,                                      /* 221*/
     DefaultISR,                                      /* 222*/
     DefaultISR,                                      /* 223*/
     DefaultISR,                                      /* 224*/
     DefaultISR,                                      /* 225*/
     DefaultISR,                                      /* 226*/
     DefaultISR,                                      /* 227*/
     DefaultISR,                                      /* 228*/
     DefaultISR,                                      /* 229*/
     DefaultISR,                                      /* 230*/
     DefaultISR,                                      /* 231*/
     DefaultISR,                                      /* 232*/
     DefaultISR,                                      /* 233*/
     DefaultISR,                                      /* 234*/
     DefaultISR,                                      /* 235*/
     DefaultISR,                                      /* 236*/
     DefaultISR,                                      /* 237*/
     DefaultISR,                                      /* 238*/
     DefaultISR,                                      /* 239*/
     DefaultISR,                                      /* 240*/
     DefaultISR,                                      /* 241*/
     DefaultISR,                                      /* 242*/
     DefaultISR,                                      /* 243*/
     DefaultISR,                                      /* 244*/
     DefaultISR,                                      /* 245*/
     DefaultISR,                                      /* 246*/
     DefaultISR,                                      /* 247*/
     DefaultISR,                                      /* 248*/
     DefaultISR,                                      /* 249*/
     DefaultISR,                                      /* 250*/
     DefaultISR,                                      /* 251*/
     DefaultISR,                                      /* 252*/
     DefaultISR,                                      /* 253*/
     DefaultISR                                      /* 254*/
};


