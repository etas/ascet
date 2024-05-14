package ascet.IN;
import types.T_Analogue;
import enumerations.S32K144_Gpio;

@c_code
stateless
class IN_AnaIn {

/* Get contents of ADC register for channel requested */

	public T_Analogue getADCIn(S32K144_Gpio port);
	
}