
#ifdef PC
return(0);

#endif 

#ifdef S32K144EVB

	return(HA_GetGPIOIn(port));

#endif

