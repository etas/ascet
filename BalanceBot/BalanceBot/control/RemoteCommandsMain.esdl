package control;
import classes.Balance2WD;

import interfaces.IRemoteCommands;

singleton class RemoteCommandsMain
reads IRemoteCommands.Mode {

	public static Balance2WD Balance2WD;
	RemoteCommands rc;

	@thread
	public void calc() {
		rc.mode = IRemoteCommands.Mode;
		rc.trig();
	}
}