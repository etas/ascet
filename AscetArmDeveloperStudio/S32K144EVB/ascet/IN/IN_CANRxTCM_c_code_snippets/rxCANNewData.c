#ifdef PC
return(0);
#else
uint8 retval;
uint8 status;

	retval = (uint8)0; /* Assume no new data */

	/* Initialised, and handle was good? */
	if (IN_CANRxHandle != HA_CANNOHANDLE)
		{
        	/* Determine if received message since last time */
        	status = HA_CANReceiveMessage(IN_CANRxHandle,rxdata);

        	/* New message? */
        	if ((status & HA_CANNEWDATA) == HA_CANNEWDATA)
        		{
        			retval = (uint8)1;
        		}
		}
	else
	/* Bad handle */
		{
		}

return (retval);
#endif
