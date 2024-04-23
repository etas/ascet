package interfaces;
import control.EModes;

data interface IRemoteCommands {
	
	@symbol("Mode")
	EModes Mode = EModes.STOP_BALANCING;	
	
}