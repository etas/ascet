package ascet.IN;
import enumerations.H_Status;
import types.T_CANHandle;
import types.T_CANTCMLever;
@c_code
stateless
class IN_CANRxTCM {

	/* Call CAN receive - new data. Must be called first! */
	public boolean rxCANNewData(T_CANHandle IN_CANRxHandle);

	/* Receive contents of CAN message - ONLY if newdata! */
	public T_CANTCMLever rxCANMsg();
	
}