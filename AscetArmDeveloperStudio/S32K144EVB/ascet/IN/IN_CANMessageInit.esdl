package ascet.IN;
import types.T_CANChannel;
import types.T_CANHandle;
import types.T_CANID;
import types.T_CANLength;
@c_code
stateless
class IN_CANMessageInit {

	/* Initialise CAN handler */
	public T_CANHandle initCANMsg(T_CANChannel IN_CANChannel, T_CANID IN_CANID, boolean IN_TxMsg, boolean IN_ExtendedMsg, T_CANLength IN_MsgLength);

	
}