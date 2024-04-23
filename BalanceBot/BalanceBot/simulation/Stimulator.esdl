package simulation;
import control.EModes;

import interfaces.IRemoteCommands;
import interfaces.IBalance2WD;

singleton class Stimulator 

writes IRemoteCommands.Mode, IBalance2WD.UltraSonicSignalRuntimeInMicroSeconds {

	characteristic EModes mode = EModes.STOP_BALANCING;
	characteristic integer microseconds = 3500; // < 1764 is < 30cm; < 2941 is < 50cm
	
	@thread
	public void stimulate() {
		IRemoteCommands.Mode = mode;
		IBalance2WD.UltraSonicSignalRuntimeInMicroSeconds = microseconds;
	}

}