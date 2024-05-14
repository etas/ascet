package ascet.IN;
import enumerations.S32K144_Gpio;

@c_code
stateless
class IN_DigitalIn {

/* Get contents of ADC register for channel requested */

	public boolean getDigitalIn(S32K144_Gpio port);
	
}