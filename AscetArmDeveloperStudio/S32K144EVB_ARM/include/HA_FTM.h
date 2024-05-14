#ifndef HA_FTM_H_
#define HA_FTM_H_

#define PCC_CGC_MASK        0x40000000    			/* Bit to enable/disable gated clock */
#define PCC_FTM0_CLK_SEL    0x06000000    			/* Selects SPLL_CLK as FTM0 clock */

#define FTM_PS_FACTOR       (U32)0x0              	/* Prescale */
#define FTM_CLKSOURCE       (U32)((U32)0x1 << 3)  	/* Clock select */
#define FTM_CPWMSEL         (U32)((U32)0x1 << 5)  	/* Centre-Aligned PWM select */
#define FTM_RIESEL          (U32)((U32)0x1 << 6)  	/* Re-load Interrupt enable */
#define FTM_RFMASK          (U32)((U32)0x1 << 7)  	/* Mask for Reload flag */
#define FTM_TOIESEL         (U32)((U32)0x1 << 8)  	/* Timer overflow interrupt enable */
#define FTM_TOFMASK         (U32)((U32)0x1 << 9)  	/* Mask for Timer overflow flag */

#define FTM_IC_DUALEDGE     0x0000000C       		/* Dual edge capture */
#define FTM_MSA_ELSA        0x00000054       		/* Capture set via ELSA, MSA and channel interrupt bits */
#define FTM_ELSB_CHIE       0x00000048       		/* Capture set via ELSB, Interrupt enabled */
#define FTM_SINGLEEDGE_INT  0x00000044       		/* Rising edge capture with interrupt */
#define FTM_BIDIEDGE_INT    0x0000004C       		/* Rising or falling edge with interrupt */

#define FTM_CHF_MASK        0x00000080       		/* Mask for Channel(n) Flag */
#define FTM_CHF_CLEAR       0x0000FF7F       		/* Channel Flag Reset */
#define FTM_CHIS_MASK       0x00000200       		/* Channel input state mask */

#define FTM_MAXCOUNT        0xFFFF					/* Maximum count of standard FTM */
#define FTM_TOFCLEAR        0xFFFFFDFF       		/* Mask to write a zero to TOF */

#define HA_FREQCHANNELS     8
#define HA_COUNTSTOUS		(U8)80
#define HA_PERCENTSCALING	(U16)10000		 		/* 0.01% expected for ASCET formula */
#define HA_SPEEDPRESCALERPM	(U64)4800000000   		/* 80MHz x 60 */
#define HA_PERIODUNDERFLOW  (U32)0xFFFFEFFF			/* Maximum period to watch for */
#define HA_PWMCOUNTERFREQ	(U32)10000000			/* Frequency of PWM counter */

#define HA_FTM3INITTRIG     0x1C

extern void HA_FTMInit(void);						/* Initialisation function calls */
extern void HA_FTM0Init(void);
extern void HA_FTM1Init(void);
extern void HA_FTM2Init(void);
extern void HA_FTM3Init(void);
extern void HA_FTMStart(void);						/* Call to start timers */

													/* Functions for external access */
extern void HA_SetPWM(U8 port, U16 freq, U16 duty);
extern U32 HA_GetFTMHigh(U8 port);
extern U32 HA_GetFTMPeriod(U8 port);
extern S16 HA_GetFTMFreq(U8 port, U8 ppr, U32 timeout);
extern U16 HA_GetFTMDuty(U8 port, U32 timeout);

#endif /* HA_FTM_H_ */
