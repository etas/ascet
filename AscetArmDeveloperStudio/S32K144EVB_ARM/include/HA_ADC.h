#ifndef HA_ADC_H_
#define HA_ADC_H_

#define  ADC_AV_4_SAMPLES     0x00U
#define  ADC_AV_8_SAMPLES     0x01U
#define  ADC_AV_16_SAMPLES    0x02U
#define  ADC_AV_32_SAMPLES    0x03U

#define  ADC_RESET_SAMPLETIME 0x0CU

#define  ADC_CLOCK_DIV1        (0x00U <<5)
#define  ADC_CLOCK_DIV2        (0x01U <<5)
#define  ADC_CLOCK_DIV4        (0x02U <<5)
#define  ADC_CLOCK_DIV8        (0x03U <<5)

#define ADC_CONV8              (0x00 << 2)
#define ADC_CONV12             (0x01 << 2)
#define ADC_CONV10             (0x02 << 2)

#define ADC_CKDIV1             (0x00 << 5)
#define ADC_CKDIV2             (0x01 << 5)
#define ADC_CKDIV4             (0x02 << 5)
#define ADC_CKDIV8             (0x03 << 5)

#define ADC_SLOWPCCCLK         0xC1000000

/* Channels assigned for general use on board */
/* ADC0 */
#define HA_ANAA0				(U8)0
#define HA_ANAA1				(U8)1
#define HA_ANAA6				(U8)2
#define HA_ANAA7				(U8)3
#define HA_ANAC0				(U8)4
#define HA_ANAC1				(U8)5
#define HA_ANAC2				(U8)6
#define HA_ANAC14				(U8)7
/* ADC1 */
#define HA_ANAD4				(U8)8
#define HA_ANAB12				(U8)9
#define HA_ANAB13				(U8)10
#define HA_ANAE2				(U8)11
#define HA_ANAE6				(U8)12
#define HA_ANAA15				(U8)13
#define HA_ANAA16				(U8)14
#define HA_ANAB0				(U8)15
#define HA_ANAB1				(U8)16
#define HA_ANALLENGTH			(U8)17
#define HA_ADCRESULTMASK    	0x00000FFF


/* Results assigned for general use on board */
/* ADC0 */
#define HA_ANAA0RESULT			(U16)((ADC0->R[0] ) << 4)
#define HA_ANAA1RESULT			(U16)((ADC0->R[1] ) << 4)
#define HA_ANAA6RESULT			(U16)((ADC0->R[2] ) << 4)
#define HA_ANAA7RESULT			(U16)((ADC0->R[3] ) << 4)
#define HA_ANAC0RESULT			(U16)((ADC0->R[4] ) << 4)
#define HA_ANAC1RESULT			(U16)((ADC0->R[5] ) << 4)
#define HA_ANAC2RESULT			(U16)((ADC0->R[6] ) << 4)
#define HA_ANAC14RESULT			(U16)((ADC0->R[7] ) << 4)

/* ADC1 */
#define HA_ANAD4RESULT			(U16)((ADC1->R[0] ) << 4)
#define HA_ANAB12RESULT			(U16)((ADC1->R[1] ) << 4)
#define HA_ANAB13RESULT			(U16)((ADC1->R[2] ) << 4)
#define HA_ANAE2RESULT			(U16)((ADC1->R[3] ) << 4)
#define HA_ANAE6RESULT			(U16)((ADC1->R[4] ) << 4)
#define HA_ANAA15RESULT			(U16)((ADC1->R[5] ) << 4)
#define HA_ANAA16RESULT			(U16)((ADC1->R[6] ) << 4)
#define HA_ANAB0RESULT			(U16)((ADC1->R[7] ) << 4)		/* Note: Channels switched per cycle */
#define HA_ANAB1RESULT			(U16)((ADC1->R[7] ) << 4)		/* Note: Channels switched per cycle */

extern volatile U16 HA_ADCResults[HA_ANALLENGTH];

/* Access functions for external code */
extern U16 HA_getAdc (U8 chan);
extern void HA_InitADC(void);

#endif /* HA_ADC_H_ */
