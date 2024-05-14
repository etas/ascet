package types;
import enumerations.H_Status;

type T_LeverOut is struct {
	T_Bitfield2 LVR_ParkSwitch;
	T_Bitfield2 LVR_ReverseSwitch;
	T_Bitfield2 LVR_NeutralSwitch;
	T_Bitfield2 LVR_DriveSwitch;
	T_Bitfield2 LVR_SportSwitch;
	T_Bitfield2 LVR_ManualSwitch;
	T_Bitfield2 LVR_PlusSwitch;
	T_Bitfield2 LVR_MinusSwitch;
	T_Bitfield8 LVR_TestResponse;
	H_Status LVR_Status;
};