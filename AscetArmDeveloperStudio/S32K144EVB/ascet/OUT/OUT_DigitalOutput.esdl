package ascet.OUT;
import types.T_HwChannel;
import enumerations.S32K144_Gpio;

@c_code
stateless
class OUT_DigitalOutput {

	public void setDigOut(S32K144_Gpio port, boolean stat);
	
}