#ifdef PC
return(1);
#else
sint8 handleret;

/* Attempt to get a handle for a CAN message being initialised */
	handleret = HA_CANInitialiseMessage(((IN_TxMsg == true)?HA_CANTXMESSAGE:HA_CANRXMESSAGE), IN_CANChannel, ((IN_ExtendedMsg == true)?HA_CANEXTENDEDID:HA_CANSTANDARDID), IN_MsgLength, IN_CANID);

return (handleret);
#endif

