#ifndef HA_GPIO_H_
#define HA_GPIO_H_

#include "S32K144.h"

#define PORTB_MINCHANNEL       18
#define PORTC_MINCHANNEL       36
#define PORTD_MINCHANNEL       54
#define PORTE_MINCHANNEL       72
#define PORTE_MAXCHANNEL       88

/* Bit definitions for GPIO pin access */
#define GPIO_BIT_0                   0x00000001U
#define GPIO_BIT_1                   0x00000002U
#define GPIO_BIT_2                   0x00000004U
#define GPIO_BIT_3                   0x00000008U
#define GPIO_BIT_4                   0x00000010U
#define GPIO_BIT_5                   0x00000020U
#define GPIO_BIT_6                   0x00000040U
#define GPIO_BIT_7                   0x00000080U
#define GPIO_BIT_8                   0x00000100U
#define GPIO_BIT_9                   0x00000200U
#define GPIO_BIT_10                  0x00000400U
#define GPIO_BIT_11                  0x00000800U
#define GPIO_BIT_12                  0x00001000U
#define GPIO_BIT_13                  0x00002000U
#define GPIO_BIT_14                  0x00004000U
#define GPIO_BIT_15                  0x00008000U
#define GPIO_BIT_16                  0x00010000U
#define GPIO_BIT_17                  0x00020000U
#define GPIO_BIT_18                  0x00040000U

#define FTM_CHIS_BIT                 0x00000200U

extern void HA_GPIOInit (void);
extern void HA_SetGPIOOut(U8 chan, U8 stat);
extern U8 HA_GetGPIOIn(U8 chan);
extern void HA_ToggleGPIOOut(U32 port, U8 chan);

#endif /* HA_GPIO_H_ */
