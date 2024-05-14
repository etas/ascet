package ascet.OUT;
import types.T_CANLeverTCM;
import enumerations.H_Status;
import types.T_CANHandle;

@c_code
stateless
class OUT_CANTxLever {
	
	/* Call CAN transmit */
	public H_Status txCANMsg(T_CANHandle OUT_CANTxHandle, T_CANLeverTCM OUT_CANTxMsg);
	
}