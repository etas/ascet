package ascet.OUT;
import enumerations.H_Status;
import types.T_CANHandle;
import types.T_InputCapture;

@c_code
stateless
class OUT_CANTxIC {
	
	/* Call CAN transmit */
	public H_Status txCANMsg(T_CANHandle OUT_CANTxHandle, T_InputCapture OUT_CANTxMsg, boolean OUT_CANTxMux);
	
}