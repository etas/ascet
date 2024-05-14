package ascet.OUT;
import types.T_DutyPercent;
import types.T_DriveFreq;
import enumerations.S32K144_Gpio;

@c_code
stateless
class OUT_PWMOutput {

	public void setPWMOut(S32K144_Gpio port, T_DutyPercent duty, T_DriveFreq freq);
	
}