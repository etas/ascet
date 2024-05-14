#ifdef PC
return(1);
#else
uint8 retval;
static uint8 msg[8];
uint8 crc;

	/* Initialised, and handle was good? */
	if (OUT_CANTxHandle != HA_CANNOHANDLE)
		{
			/* Populate the CAN frame, with '1' in unused bits */
			msg[0] = (OUT_CANTxMsg.LVR_ParkSwitch << 6) | (OUT_CANTxMsg.LVR_ReverseSwitch << 4) | (OUT_CANTxMsg.LVR_NeutralSwitch << 2) | (OUT_CANTxMsg.LVR_DriveSwitch);
			msg[1] = (OUT_CANTxMsg.LVR_SportSwitch << 6) | (OUT_CANTxMsg.LVR_ManualSwitch << 4) | (OUT_CANTxMsg.LVR_PlusSwitch << 2) | (OUT_CANTxMsg.LVR_MinusSwitch);
			msg[2] = OUT_CANTxMsg.LVR_TestResponse;
			msg[3] = 0xFF;
			msg[4] = 0xFF;
			msg[5] = 0xFF;
			msg[6] = 0xF0 | OUT_CANTxMsg.LVR_Counter;
			/* Calculate a simple checksum */
			crc = (uint8)0xFF ^ msg[0];
			crc = crc ^ msg[1];
			crc = crc ^ msg[2];
			crc = crc ^ msg[3];
			crc = crc ^ msg[4];
			crc = crc ^ msg[5];
			crc = crc ^ msg[6];
			msg[7] = (uint8)0xFF - crc;

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
