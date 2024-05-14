#ifdef PC
return(1);
#else
uint8 retval;
static uint8 msg[8];

	/* Initialised, and handle was good? */
	if (OUT_CANTxHandle != HA_CANNOHANDLE)
		{
			msg[0] = (uint8)((OUT_CANTxMux << 7) | (OUT_CANTxMsg.IN_Pin << 6) | ((OUT_CANTxMsg.IN_Duty & 0x3F00) >> 8));
			msg[1] = (uint8)(OUT_CANTxMsg.IN_Duty & 0x00FF);
			msg[2] = (uint8)((OUT_CANTxMsg.IN_Speed & 0xFF00) >> 8);
			msg[3] = (uint8)(OUT_CANTxMsg.IN_Speed & 0x00FF);
			if (OUT_CANTxMux != (uint8)0)
				{
					msg[4] = (uint8)((OUT_CANTxMsg.IN_Period & 0xFF000000) >> 24);
					msg[5] = (uint8)((OUT_CANTxMsg.IN_Period & 0x00FF0000) >> 16);
					msg[6] = (uint8)((OUT_CANTxMsg.IN_Period & 0x0000FF00) >> 8);
					msg[7] = (uint8)((OUT_CANTxMsg.IN_Period & 0x000000FF));
				}
			else
				{
					msg[4] = (uint8)((OUT_CANTxMsg.IN_HighTime & 0xFF000000) >> 24);
					msg[5] = (uint8)((OUT_CANTxMsg.IN_HighTime & 0x00FF0000) >> 16);
					msg[6] = (uint8)((OUT_CANTxMsg.IN_HighTime & 0x0000FF00) >> 8);
					msg[7] = (uint8)((OUT_CANTxMsg.IN_HighTime & 0x000000FF));
				}

			/* Transmit CAN data on given handle */
			(void) HA_CANTransmitMessage(OUT_CANTxHandle, msg);
			retval = (uint8)1; /* H_Okay return */
		}
	else
	/* Bad handle */
		{
			retval = (uint8)5; /* H_Implausible return */
		}

return (retval);
#endif
