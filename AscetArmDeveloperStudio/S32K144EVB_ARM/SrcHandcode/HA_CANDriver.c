#include "HA_Types.h"
#include "S32K144.h"
#include "HA_CANDriver.h"

void HA_CANInit(U8 HA_CANType, U32 *initCAN);
U8 HA_SetupCANBuffer(U32 * initCAN, U32 HA_MessageID, U8 HA_IDLen, U8 HA_Length, U8 HA_Type);
U8 HA_CANGetBufferNumber(U32 * initCAN, U32 HA_MessageID, U8 HA_IDLen);
U8 HA_CANGetMessage(U32 * HA_CanModuleAddress, U8* HA_MsgPtr, U8 HA_MsgBuff, U8* HA_Timer, U8* HA_MsgDLC);
U8 HA_CANSendMessage(U32* HA_CanModuleAddress, U8* HA_MsgPtr, U8 HA_MsgBuff, U8* HA_Timer, U8 HA_MsgDLC, U32 HA_MessageID);
U32 HA_GetCANStatus(U32 * HA_CanModuleAddress);

void HA_CANInitialiseBus(U8 canbus, U8 speed);
S8 HA_CANInitialiseMessage(U8 msgtype,U8 canbus,U8 idtype, U8 len, U32 id);
U8 HA_CANReceiveMessage(S8 handle, U8 * msg);
U8 HA_CANTransmitMessage(S8 handle, U8 * msg);

#define HA_NUMCANHANDLES	(U8)30
static S8 HA_Handle = (S8)0;
static U8 HA_Bus[HA_NUMCANHANDLES];
static U8 HA_Buffer[HA_NUMCANHANDLES];
static U32 HA_Id[HA_NUMCANHANDLES];
static U8 HA_Dlc[HA_NUMCANHANDLES];

const U8 HA_CANByteExchange[8] = {3,2,1,0,7,6,5,4};

void HA_CANInitialiseBus(U8 canbus, U8 speed)
{
U32 canbaseadd;
	switch (canbus)
		{
			case 0:
				canbaseadd = CAN0_BASE;
			break;
			case 1:
				canbaseadd = CAN1_BASE;
			break;
			case 2:
				canbaseadd = CAN2_BASE;
			break;
			default:
				canbaseadd = CAN0_BASE;
			break;
		}
	if (canbaseadd != HA_NULLADDRESS)
		{
			HA_CANInit(speed, (U32 *)canbaseadd);
		}
	HA_Handle = (S8)0;
}

/* Function initialises a message on a given CAN bus, and returns a handle */
S8 HA_CANInitialiseMessage(U8 msgtype,U8 canbus,U8 idtype, U8 len, U32 id)
{
U32 canbaseadd;
S8 handle;
U8 buffer;

	canbaseadd = HA_NULLADDRESS;
	handle = HA_CANNOHANDLE;

	switch (canbus)
		{
			case 0:
				canbaseadd = CAN0_BASE;
			break;
			case 1:
				canbaseadd = CAN1_BASE;
			break;
			case 2:
				canbaseadd = CAN2_BASE;
			break;
			default:
			break;
		}

	if (canbaseadd != HA_NULLADDRESS)
		{
			/* msgtype - Tx or Rx */
			/* canbus - bus number */
			/* idtype - standard/extended */
			/* len - DLC */
			/* id - CAN identifier */
			buffer = HA_SetupCANBuffer((U32 *)canbaseadd, id,  idtype, len, msgtype);
			if (buffer != BUFFERERRMARKER)
				{	/* A buffer is available, so store access information for Tx/Rx */
					HA_Handle += (S8)1;
					handle = HA_Handle;
					HA_Bus[HA_Handle] = canbus;
					HA_Buffer[HA_Handle] = buffer;
					HA_Id[HA_Handle] = id;
					HA_Dlc[HA_Handle] = len;
				}
			 /* Else not needed */
		}
	/* Else not needed */
	return (handle);
}

/* Function receives a CAN message given a handle */
U8 HA_CANReceiveMessage(S8 handle, U8 * msg)
{
U8 retval;
U32 canbaseadd;
U8 timer;

	retval = (U8)0;

	if ((handle != HA_CANNOHANDLE) && (handle != (S8)0))
		{
			switch (HA_Bus[handle])
				{
					case 0:
						canbaseadd = CAN0_BASE;
					break;
					case 1:
						canbaseadd = CAN1_BASE;
					break;
					case 2:
						canbaseadd = CAN2_BASE;
					break;
					default:
						canbaseadd = CAN0_BASE;
					break;
				}
			retval = HA_CANGetMessage((U32 *)canbaseadd, msg, HA_Buffer[handle], &timer, &HA_Dlc[handle]);
			if (retval == TRUE_U8)
				{
					retval = HA_CANNEWDATA;
				}
			else
				{
					retval = HA_CANNONEWDATA;
				}
		}
	return (retval);
}

/* Function transmits a CAN message given a handle */
U8 HA_CANTransmitMessage(S8 handle, U8 * msg)
{
	U8 retval;
	U32 canbaseadd;
	U8 timer;

		retval = HA_CANNONEWDATA;

		if ((handle != HA_CANNOHANDLE) && (handle != (S8)0))
			{
				switch (HA_Bus[handle])
					{
						case 0:
							canbaseadd = CAN0_BASE;
						break;
						case 1:
							canbaseadd = CAN1_BASE;
						break;
						case 2:
							canbaseadd = CAN2_BASE;
						break;
						default:
							canbaseadd = CAN0_BASE;
						break;
					}
				retval = HA_CANSendMessage((U32 *)canbaseadd, msg, HA_Buffer[handle], &timer, HA_Dlc[handle], HA_Id[handle]);
				if (retval == (U8)0)
					{
						retval = HA_CANNEWDATA;
					}
				else
					{
						retval = HA_CANNONEWDATA;
					}
			}
		return (retval);
}


void HA_CANInit(U8 HA_CANType, U32 *initCAN)
{
	U8 bufcount;
	U8 maxbuf;
	CAN_Type * CANPort;
	CAN_MBUFS * CANBuffers;

	CANPort = (void *)initCAN;
	CANBuffers = (void *)((U32)initCAN + BUFFERADDROFFSET);

	if ((U32)initCAN == CAN0_BASE)
	{
		maxbuf = MAXBUF32;
	}
	else
	{
		maxbuf = MAXBUF16;
	}

	/* Disable the module for clock configuration */
	CANPort->MCR |= CAN_MCR_MDIS_MASK;
	/* Select a clock source (8MHz oscillator) */
	CANPort->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;

	/* Enable the module for remaining configuration actions */
	CANPort->MCR &= ~CAN_MCR_MDIS_MASK;

	/* Enable freeze mode, request a freeze and wait for it to be acknowledged */
	CANPort->MCR |= CAN_MCR_FRZ_MASK;
	CANPort->MCR |= CAN_MCR_HALT_MASK;
	while ((CANPort->MCR & CAN_MCR_FRZACK_MASK) != CAN_MCR_FRZACK_MASK) {;}

	switch (HA_CANType)
	{
		case (CAN_125KBPS):
		{
			CANPort->CTRL1 = CAN_125KPBS_SETTING;
		}
		break;
		case (CAN_250KBPS):
		{
			CANPort->CTRL1 = CAN_250KPBS_SETTING;
		}
		break;
		case (CAN_1MBPS):
		{
			CANPort->CTRL1 = CAN_1MBPS_SETTING;
		}
		break;
		default:
		{
			CANPort->CTRL1 = CAN_500KPBS_SETTING;
		}
		break;
	}

	/* Initialise the message buffer RAM. Depends on the number of available buffers */
	for (bufcount = 0; bufcount < (maxbuf << 2); bufcount++)
	{
		/* Set the incoming message flags */
		CANPort->RAMn[bufcount] = 0;
	}

	for (bufcount = 0; bufcount < maxbuf; bufcount++)
	{
		/* Initialise buffers with ineffective entries */
		CANBuffers->BUF8.MB8[bufcount].CS.B.EDL = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.BRS = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.ESI = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.CODE = RX_CODEINACTIVE;
		CANBuffers->BUF8.MB8[bufcount].ID.B.ID_STD = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.DLC = 8;
		CANBuffers->BUF8.MB8[bufcount].CS.B.SRR = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.IDE = 0;
		CANBuffers->BUF8.MB8[bufcount].CS.B.RTR = 0;
	}

	for (bufcount = 0; bufcount < maxbuf; bufcount++)
	{
		/* Set the incoming message flags */
		CANPort->RXIMR[bufcount] = 0xFFFFFFFF;
	}

	CANPort->RXMGMASK = CAN_GLOBALMASK;

	/* Set the number of buffers up */
	/* Bring out of freeze mode and wait for it to come out */
	CANPort->MCR = (U32)(CAN_MCR_SUPV_MASK | (U8)(maxbuf - 1));

	while (CANPort->MCR & CAN_MCR_FRZACK_MASK) {;}

	/* Wait until peripheral is synchronised */
	while (CANPort->MCR & CAN_MCR_NOTRDY_MASK) {;}

}

U8 HA_SetupCANBuffer(U32 * initCAN, U32 HA_MessageID, U8 HA_IDLen, U8 HA_Length, U8 HA_Type)
{
	U8 bufcount;
	U8 maxbuf;
	CAN_MBUFS * CANBuffers;

	/* Set up pointers to memory locations and maximum buffer number */
	CANBuffers = (void *)((U32)initCAN + BUFFERADDROFFSET);

	if ((U32)initCAN == CAN0_BASE)
	{
		maxbuf = MAXBUF32;
	}
	else
	{
		maxbuf = MAXBUF16;
	}

	bufcount = 0;
	/* Loop round the available buffers, checking for the first available one */
	while((bufcount < maxbuf) && (CANBuffers->BUF8.MB8[bufcount].CS.B.CODE != RX_CODEINACTIVE))
	{
		bufcount++;
	}

	if (bufcount < maxbuf)
	{
		/* Buffer can be assigned using supplied information */
		if (HA_IDLen)
		{
			/* Extended ID format */
			CANBuffers->BUF8.MB8[bufcount].CS.B.IDE = 1;
			CANBuffers->BUF8.MB8[bufcount].ID.B.ID_EXT = HA_MessageID;
			CANBuffers->BUF8.MB8[bufcount].CS.B.RTR = 0;
			CANBuffers->BUF8.MB8[bufcount].CS.B.SRR = 1;
		}
		else
		{
			/* 11bit ID format */
			CANBuffers->BUF8.MB8[bufcount].CS.B.IDE = 0;
			CANBuffers->BUF8.MB8[bufcount].ID.B.ID_STD = HA_MessageID;
			CANBuffers->BUF8.MB8[bufcount].CS.B.RTR = 0;
			CANBuffers->BUF8.MB8[bufcount].CS.B.SRR = 0;
		}

		CANBuffers->BUF8.MB8[bufcount].CS.B.DLC = HA_Length;

		if (HA_Type)
		{
			/* Transmit buffer */
			CANBuffers->BUF8.MB8[bufcount].CS.B.CODE = TX_CODEINACTIVE;
		}
		else
		{
			/* Receive buffer */
			CANBuffers->BUF8.MB8[bufcount].CS.B.CODE = RX_CODEEMPTY;
		}
	}
	else
	{
		bufcount = BUFFERERRMARKER;
	}

	return(bufcount);
}

U8 HA_CANGetBufferNumber(U32 * initCAN, U32 HA_MessageID, U8 HA_IDLen)
{
	CAN_MBUFS * CANBuffers;
	U8 bufcount;
	U8 maxbuf;
	U8 buffound;

	/* Set up pointer to memory location and maximum buffer number */
	CANBuffers = (void *)((U32)initCAN + BUFFERADDROFFSET);

	if ((U32)initCAN == CAN0_BASE)
	{
		maxbuf = MAXBUF32;
	}
	else
	{
		maxbuf = MAXBUF16;
	}

	bufcount =  0;
	buffound = FALSE_U8;
	while((!buffound) && (bufcount < maxbuf))
	{
		/* Search in the buffer for an ID match */
		if (HA_IDLen)
		{
			if (CANBuffers->BUF8.MB8[bufcount].ID.B.ID_EXT == HA_MessageID)
			{
				buffound = TRUE_U8;
			}
			else
			{
				bufcount++;
			}
		}
		else
		{
			if (CANBuffers->BUF8.MB8[bufcount].ID.B.ID_STD == HA_MessageID)
			{
				buffound = TRUE_U8;
			}
			else
			{
				bufcount++;
			}
		}
	}

	if(!buffound)
	{
		bufcount = BUFFERERRMARKER;
	}

	return(bufcount);
}

U8 HA_CANGetMessage(U32 * HA_CanModuleAddress, U8* HA_MsgPtr, U8 HA_MsgBuff, U8* HA_Timer, U8* HA_MsgDLC)
{
	CAN_Type * CANPort;
	CAN_MBUFS * CANBuffers;
	U32 bufmask;
	U8 bufstat;
	U8 bufcount;
	U8 maxbuf;
	U8 retval;
	U8 byteindx;

	if ((U32)HA_CanModuleAddress == CAN0_BASE)
	{
		maxbuf = MAXBUF32;
	}
	else
	{
		maxbuf = MAXBUF16;
	}

	retval = FALSE_U8;

	/* Test for buffer valid */
	if (HA_MsgBuff < maxbuf)
	{
		/* Set up pointers to memory locations */
		CANPort = (void *)HA_CanModuleAddress;
		CANBuffers = (void *)((U32)HA_CanModuleAddress + BUFFERADDROFFSET);
		bufmask = (1 << HA_MsgBuff);
		bufstat = (CANPort->IFLAG1 & bufmask);

		if (bufstat)
		{
			/* New data received, lock buffer and grab data */
			bufcount = 0;
			while((CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.CODE & RX_CODEBUSY) && (bufcount < 100))
			{
				/* Buffer is being updated by CPU - wait a bit for it to finish, otherwise carry on anyway */
				bufcount++;
			}
			if (!(CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.CODE & RX_CODEBUSY))
			{
				/* Grab the DLC - use a temp to do it */
				retval = CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.DLC;
				/* Get the new data */
				for (bufcount = 0; bufcount < retval; bufcount++)
				{
					byteindx = HA_CANByteExchange[bufcount];
					HA_MsgPtr[bufcount] = CANBuffers->BUF8.MB8[HA_MsgBuff].DATA.B[byteindx];
				}
				/* Now confirm the number of bytes received */
				*HA_MsgDLC = retval;
				/* Zero the message timeout timer */
				*HA_Timer = 0;
				/* Read CAN timer to unlock buffers */
				if (CANPort->TIMER)
				{;}
				/* Show buffer as being written here */
				retval = TRUE_U8;
				/* Clear the associated CAN flag - write 1 to clear it */
				CANPort->IFLAG1 = bufmask;
			}
			else
			{;} /* buffer shows as empty - will force eventual timeout if this condition persists */
		}
		else
		{;} /* No data this time, buffer shown as empty - will force eventual timeout */
		if (retval == FALSE_U8)
		{
			/* Have not received this time - if timer not saturated increment it */
			if (*HA_Timer < 255)
			{
				*HA_Timer = *HA_Timer + 1;
			}
		}
	}
	else
	{
		/* Buffer number passed was bad */
		retval |= BUFERRORRETURNCODE;
	}

	return (retval);
}

U8 HA_CANSendMessage(U32* HA_CanModuleAddress, U8* HA_MsgPtr, U8 HA_MsgBuff, U8* HA_Timer, U8 HA_MsgDLC, U32 HA_MessageID)
{
	CAN_MBUFS * CANBuffers;
	U8 bufcount;
	U8 maxbuf;
	U8 retval;
	U8 byteindx;

	if ((U32)HA_CanModuleAddress == CAN0_BASE)
	{
		maxbuf = MAXBUF32;
	}
	else
	{
		maxbuf = MAXBUF16;
	}

	retval = FALSE_U8;

	if (HA_MsgBuff < maxbuf)
	{
		/* Set up pointers to memory locations */
		CANBuffers = (void *)((U32)HA_CanModuleAddress + BUFFERADDROFFSET);

        /* Check if last message was sent */
		if (CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.CODE == TX_CODEINACTIVE)
		{
			/* Message was sent - zero the timer */
			*HA_Timer = 0;
		}
		else
		{
			/* Message was not sent - increment timer */
			if (*HA_Timer < 255)
			{
				*HA_Timer = *HA_Timer + 1;
			}
			/* Indicate a problem with transmit last time */
			retval = TRUE_U8;
		}

		/* Update data in transmit buffer */
		/* Force it to be inactive first */
		CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.CODE = 0;

		/* Must re-write identifier */
		if (CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.IDE)
		{
			CANBuffers->BUF8.MB8[HA_MsgBuff].ID.B.ID_EXT = HA_MessageID;
		}
		else
		{
			CANBuffers->BUF8.MB8[HA_MsgBuff].ID.B.ID_STD = HA_MessageID;
		}

		/* Write the bytes to send this time */
		for (bufcount = 0; bufcount < HA_MsgDLC; bufcount++)
		{
			byteindx = HA_CANByteExchange[bufcount];
			CANBuffers->BUF8.MB8[HA_MsgBuff].DATA.B[byteindx] = HA_MsgPtr[bufcount];
		}
		/* Set the data length */
		CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.DLC = HA_MsgDLC;

		/* Update the remaining flags */
		CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.RTR = 0;
		if (CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.IDE)
		{
			CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.SRR = 1;
		}
		else
		{
			CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.SRR = 0;
		}
		/* Set it to transmit */
		CANBuffers->BUF8.MB8[HA_MsgBuff].CS.B.CODE = TX_CODEDATA;
	}
	else
	{
		/* Buffer number passed was bad */
		retval |= BUFERRORRETURNCODE;
	}

	/* Send back the return flag*/
	return(retval);
}

U32 HA_GetCANStatus(U32 * HA_CanModuleAddress)
{
	CAN_Type * CANPort;

	/* Set up pointer to memory location */
	CANPort = (void *)HA_CanModuleAddress;

	return (CANPort->ESR1);
}
