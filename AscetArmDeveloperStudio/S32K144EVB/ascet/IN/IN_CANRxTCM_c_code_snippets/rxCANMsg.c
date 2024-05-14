static struct T_CANTCMLEVER_EVB retval;

uint8 crc;

	retval.TCM_ParkLight = (rxdata[0] & 0xC0) >> 6;
	retval.TCM_ReverseLight = (rxdata[0] & 0x30) >> 4;
	retval.TCM_NeutralLight = (rxdata[0] & 0x0C) >> 2;
	retval.TCM_DriveLight = (rxdata[0] & 0x03);

	retval.TCM_SportLight = (rxdata[1] & 0xC0) >> 6;
	retval.TCM_ManualLight = (rxdata[1] & 0x30) >> 4;
	retval.TCM_ShiftLock = (rxdata[1] & 0x0C) >> 2;
	retval.TCM_BackLight = (rxdata[1] & 0x03);

	retval.TCM_TestData1 = rxdata[2];
	retval.TCM_TestData2 = rxdata[3];
	retval.TCM_ActualGear = rxdata[4] & 0x0F;
	retval.TCM_TargetGear = (rxdata[4] & 0xF0) >> 4;
	retval.TCM_Counter = (rxdata[6] & 0x0F);
	retval.TCM_Checksum = rxdata[7];

	/* Calculate a simple checksum */
	crc = (uint8)0xFF ^ rxdata[0];
	crc = crc ^ rxdata[1];
	crc = crc ^ rxdata[2];
	crc = crc ^ rxdata[3];
	crc = crc ^ rxdata[4];
	crc = crc ^ rxdata[5];
	crc = crc ^ rxdata[6];
	crc = (uint8)0xFF - crc;

	/* Checksum okay is that data[7] matches calculated checksum */
	retval.TCM_ChecksumOkay = (crc == rxdata[7])?true:false;

return (&retval);
