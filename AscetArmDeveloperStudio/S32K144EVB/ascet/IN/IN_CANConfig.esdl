package ascet.IN;
import types.T_CANChannel;
import types.T_CANkbps;

@c_code
stateless
class IN_CANConfig {

	/* Write digital output with requested state */
	
	public void initCANChannel(T_CANChannel IN_Channel, T_CANkbps IN_Baud);
	
	public void startCANChannel(T_CANChannel IN_Channel);
		
}