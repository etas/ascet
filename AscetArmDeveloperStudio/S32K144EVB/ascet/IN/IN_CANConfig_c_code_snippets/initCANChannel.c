
#ifdef PC

#endif 

#ifdef S32K144EVB
	switch (IN_Baud)
		{
			case 125:
				HA_CANInitialiseBus(IN_Channel, CAN_125KBPS);
			break;
			case 250:
				HA_CANInitialiseBus(IN_Channel, CAN_250KBPS);
			break;
			case 500:
				HA_CANInitialiseBus(IN_Channel, CAN_500KBPS);
			break;
			case 1000:
				HA_CANInitialiseBus(IN_Channel, CAN_1MBPS);
			break;
			default:
			break;
		}
#endif
