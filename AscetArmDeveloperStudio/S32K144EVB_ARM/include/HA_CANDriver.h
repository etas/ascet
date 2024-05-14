
#ifndef HA_CANDRIVER_H_
#define HA_CANDRIVER_H_

#define CAN_125KPBS_SETTING     0x00DB0006  // TODO: Correct setting
#define CAN_250KPBS_SETTING     0x00DB0006  // TODO: Correct setting
#define CAN_500KPBS_SETTING     0x00DB0006
#define CAN_1MBPS_SETTING       0x00090002

/* CAN definitions - support for both CAN and CAN-FD */

/* Defines for CAN bit rate for CAN networks, and CAN header bit rate for CAN-FD */
#define CAN_500KBPS				(U8)0
#define CAN_125KBPS				(U8)1
#define CAN_250KBPS				(U8)2
#define CAN_1MBPS				(U8)3

/* Defines for Data Section of CAN-FD networks */
#define CANFD_DATA1MBPS			(U8)0
#define CANFD_DATA2MBPS			(U8)1
#define CANFD_DATA4MBPS			(U8)2
#define CANFD_DATA5MBPS			(U8)3
#define CANFD_DATA8MBPS			(U8)4

#define CANFD_PAYLOAD8          (U8)0
#define CANFD_PAYLOAD16         (U8)1
#define CANFD_PAYLOAD32         (U8)2
#define CANFD_PAYLOAD64         (U8)3

#define CANFD_DLCVAL8           (U8)8
#define CANFD_DLCVAL12          (U8)9
#define CANFD_DLCVAL16          (U8)10
#define CANFD_DLCVAL20          (U8)11
#define CANFD_DLCVAL24          (U8)12
#define CANFD_DLCVAL32          (U8)13
#define CANFD_DLCVAL48          (U8)14
#define CANFD_DLCVAL64          (U8)15

/* Buffer control defines */
#define BUFFERADDROFFSET        0x80
#define BUFFERERRMARKER         0xFF
#define BUFERRORRETURNCODE      0x02
#define CAN_GLOBALMASK          0x1FFFFFFF

/* Buffer status codes */
#define RX_CODEINACTIVE         0x0
#define RX_CODEEMPTY            0x4
#define RX_CODEFULL             0x2
#define RX_CODEOVERRUN          0x6
#define RX_CODERANSWER          0xA
#define RX_CODEBUSY             0x1
#define TX_CODEINACTIVE         0x8
#define TX_CODEABORT            0x9
#define TX_CODEDATA             0xC
#define TX_CODETANSWER          0xE

/* CAN buffer definitions */
/* S32 series has flexible configuration of CAN buffers to support CAN-FD */
/* Several buffer configurations are therefore possible */
/* Unions declared as per previous devices with flexibility to support CAN-FD */

typedef union CAN_MB_CS_union_tag {    /* Message Buffer 0 CS Register */
	volatile U32 R;
  struct {
	volatile U16 TIMESTAMP;           /* Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field appears on the CAN bus. */
	volatile U8 DLC:4;                /* Length of the data to be stored/transmitted. */
	volatile U8 RTR:1;                /* Remote Transmission Request. One/zero for remote/data frame. */
	volatile U8 IDE:1;                /* ID Extended. One/zero for extended/standard format frame. */
	volatile U8 SRR:1;                /* Substitute Remote Request. Contains a fixed recessive bit. */
	volatile U8  :1;
	volatile U8 CODE:4;               /* Message Buffer Code */
	volatile U8  :1;
	volatile U8 ESI:1;                /* Error State Indicator */
	volatile U8 BRS:1;                /* Bit Rate Switch - used on CAN-FD */
	volatile U8 EDL:1;                /* Extended Data Length - used on CAN-FD */
  } B;
} CAN_MB_CS_tag;

typedef union CAN_MB_ID_union_tag {    /* Message Buffer 0 ID Register */
	volatile U32 R;
  struct {
	volatile U32 ID_EXT:18;             /* Frame Identifier Extended */
	volatile U16 ID_STD:11;             /* Frame Identifier Standard */
	volatile U8 PRIO:3;                /* Local Priority */
  } B;
} CAN_MB_ID_tag;

typedef union CAN_MB_DATA_union_tag {
	volatile U8  B[8];
	volatile U16 H[4];
	volatile U32 W[2];
} CAN_MB_DATA_tag;

typedef union CAN_MB16_DATA_union_tag {
	volatile U8  B[16];
	volatile U16 H[8];
	volatile U32 W[4];
} CAN_MB16_DATA_tag;

typedef union CAN_MB32_DATA_union_tag {
	volatile U8  B[32];
	volatile U16 H[16];
	volatile U32 W[8];
} CAN_MB32_DATA_tag;

typedef union CAN_MB64_DATA_union_tag {
	volatile U8  B[64];
	volatile U16 H[32];
	volatile U32 W[16];
} CAN_MB64_DATA_tag;

typedef struct CAN_MB8_struct_tag {
  CAN_MB_CS_tag CS;                    /* Message Buffer 0 CS Register */
  CAN_MB_ID_tag ID;                    /* Message Buffer 0 ID Register */
  CAN_MB_DATA_tag DATA;
} CAN_MB8_tag;

typedef struct CAN_MB8_arrangement_tag {
	CAN_MB8_tag MB8[32];
} CAN_MB8_arrangement_tag;

typedef struct CAN_MB16_struct_tag {
  CAN_MB_CS_tag CS;                    /* Message Buffer 0 CS Register */
  CAN_MB_ID_tag ID;                    /* Message Buffer 0 ID Register */
  CAN_MB16_DATA_tag DATA;
} CAN_MB16_tag;

typedef struct CAN_MB16_arrangement_tag {
	CAN_MB16_tag MB16[21];
	volatile U32 W[2];
} CAN_MB16_arrangement_tag;

typedef struct CAN_MB32_struct_tag {
  CAN_MB_CS_tag CS;                    /* Message Buffer 0 CS Register */
  CAN_MB_ID_tag ID;                    /* Message Buffer 0 ID Register */
  CAN_MB32_DATA_tag DATA;
} CAN_MB32_tag;

typedef struct CAN_MB32_arrangement_tag {
	CAN_MB32_tag MB32[12];
	volatile U32 W[8];
} CAN_MB32_arrangement_tag;

typedef struct CAN_MB64_struct_tag {
  CAN_MB_CS_tag CS;                    /* Message Buffer 0 CS Register */
  CAN_MB_ID_tag ID;                    /* Message Buffer 0 ID Register */
  CAN_MB64_DATA_tag DATA;
} CAN_MB64_tag;

typedef struct CAN_MB64_arrangement_tag {
	CAN_MB64_tag MB64[7];
	volatile U32 W[2];
} CAN_MB64_arrangement_tag;

typedef union CAN_MBUF_union_tag {
	CAN_MB8_arrangement_tag BUF8;
	CAN_MB16_arrangement_tag BUF16;
	CAN_MB32_arrangement_tag BUF32;
    CAN_MB64_arrangement_tag BUF64;
} CAN_MBUFS;

#define MAXBUF16                16
#define MAXBUF32                32

#define HA_CANRXMESSAGE	(U8)0
#define HA_CANTXMESSAGE	(U8)1
#define HA_CANSTANDARDID   (U8)0
#define HA_CANEXTENDEDID   (U8)1

#define HA_CANNOHANDLE     (S8)-1
#define HA_CANNONEWDATA	(U8)0x00
#define HA_CANNEWDATA		(U8)0x01
#define HA_NULLADDRESS		(U32)0

extern void HA_CANInitialiseBus(U8 canbus, U8 speed);
extern S8 HA_CANInitialiseMessage(U8 msgtype,U8 canbus,U8 idtype, U8 len, U32 id);
extern U8 HA_CANReceiveMessage(S8 handle, U8 * msg);
extern U8 HA_CANTransmitMessage(S8 handle, U8 * msg);

#endif /* HA_CANDRIVER_H_ */
