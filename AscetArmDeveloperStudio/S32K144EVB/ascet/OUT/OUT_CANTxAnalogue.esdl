package ascet.OUT;
import types.T_CANTxAnalogue;
import enumerations.H_Status;
import types.T_CANHandle;

@c_code
stateless
class OUT_CANTxAnalogue {

	/* Call CAN transmit */
	public H_Status txCANMsg(T_CANHandle OUT_CANTxHandle, T_CANTxAnalogue OUT_CANTxMsg);
	
}