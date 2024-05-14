
#ifdef PC
return(0);

#endif 

#ifdef S32K144EVB

U16 uadc;

	uadc = HA_getAdc(port);

return (uadc);
#endif
