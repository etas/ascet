#ifdef PC
return(1);
#else
	HA_SetPWM(port, freq, duty);
#endif
