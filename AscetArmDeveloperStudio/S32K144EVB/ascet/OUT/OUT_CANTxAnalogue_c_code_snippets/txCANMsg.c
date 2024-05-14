#ifdef PC
return(1);
#else
uint8 retval;
static uint8 msg[8];

	/* Initialised, and handle was good? */
	if (OUT_CANTxHandle != HA_CANNOHANDLE)
		{
			msg[0] = (OUT_CANTxMsg.OUT_Analogue1 & 0xFF00) >> 8;
			msg[1] = (OUT_CANTxMsg.OUT_Analogue1 & 0x00FF);
			msg[2] = (OUT_CANTxMsg.OUT_Analogue2 & 0xFF00) >> 8;
			msg[3] = (OUT_CANTxMsg.OUT_Analogue2 & 0x00FF);
			msg[4] = (OUT_CANTxMsg.OUT_Analogue3 & 0xFF00) >> 8;
			msg[5] = (OUT_CANTxMsg.OUT_Analogue3 & 0x00FF);
			msg[6] = (OUT_CANTxMsg.OUT_Analogue4 & 0xFF00) >> 8;
			msg[7] = (OUT_CANTxMsg.OUT_Analogue4 & 0x00FF);

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
