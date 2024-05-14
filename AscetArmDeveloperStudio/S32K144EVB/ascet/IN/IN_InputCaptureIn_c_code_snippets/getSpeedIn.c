static struct T_INPUTCAPTURE_EVB retval;

#ifdef PC
	retval.IN_Pin = (uint8)0;
	retval.IN_Duty = (uint16)0;
	retval.IN_Speed = (sint16)0;
	retval.IN_HighTime = (uint32)0;
	retval.IN_Period = (uint32)0;
#endif 

#ifdef S32K144EVB
	retval.IN_Pin = HA_GetGPIOIn(port);
	retval.IN_Duty = HA_GetFTMDuty(port,timeout);
	retval.IN_Speed = HA_GetFTMFreq(port,ppr,timeout);
	retval.IN_HighTime = HA_GetFTMHigh(port);
	retval.IN_Period = HA_GetFTMPeriod(port);
#endif

return (&retval);
