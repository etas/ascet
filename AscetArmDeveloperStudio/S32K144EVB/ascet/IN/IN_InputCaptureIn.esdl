package ascet.IN;
import enumerations.S32K144_Gpio;
import types.T_Timeus;
import types.T_SpeedPpr;
import types.T_InputCapture;

@c_code
stateless
class IN_InputCaptureIn {
		public T_InputCapture getSpeedIn(S32K144_Gpio port, T_Timeus timeout, T_SpeedPpr ppr);
		
}