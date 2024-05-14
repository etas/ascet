package types;
import formulas.f_anin;
import formulas.f_0bn0;
import formulas.f_0bn6;
import formulas.f_0bn8;
import formulas.f_0bn10;

/* Execution rate of classes */
representation R_Intensity {
	range = 0 .. 255;
	datatype = uint8;
	formula = f_0bn8;
}

representation R_IIRCoeff2n64 {
	range = 0 .. 63;
	datatype = uint16;
	formula = f_0bn6;
}

representation R_Volts {
	range = 0 .. 65535;
	datatype = uint16;
	formula = f_anin;
}

representation R_Speed {
	range = -32768 .. 32767;
	datatype = sint16;
	formula = f_0bn0;
}

representation R_SpeedHR {
	range = -2147483648 .. 2147483647;
	datatype = sint32;
	formula = f_0bn10;
}

representation R_SpeedGrad {
	range = -32768 .. 32767;
	datatype = sint16;
	formula = f_0bn0;
}

/* Real (cont) types */
type T_Analogue is real using R_Volts;
type T_Speed is real using R_Speed;
type T_SpeedHR is real using R_SpeedHR;
type T_SpeedGradient is real using R_SpeedGrad;
type T_Time is real 0.0 .. 65.530 delta 0.001;
type T_Time5ms is real 0.0 .. 327.600 delta 0.005;
type T_DutyPercent is real 0.0 .. 100.0 delta 0.01;
type T_DutyPercSigned is real -100.0 .. 100.0 delta 0.01;
type T_DutyPercentHR is real 0.0 .. 100.0 delta 0.00001;
type T_DutyPercSignHR is real -100.0 .. 100.0 delta 0.00001;
type T_Timeus is real 0.0 .. 4294967295.0;
type T_IIRCoeff is real 0.0 .. 1.0 delta 0.001;
type T_IIRCoeff2n64 is real using R_IIRCoeff2n64;
type T_DriveFreq is real 4.0 .. 5000.0;
type T_Intensity is real using R_Intensity;

/* Integer (disc) types */
type T_Bitfield2 is integer 0 .. 3;
type T_Bitfield3 is integer 0 .. 7;
type T_Bitfield4 is integer 0 .. 15;
type T_Bitfield5 is integer 0 .. 31;
type T_Bitfield8 is integer 0 .. 255;
type T_Bitfield16 is integer 0 .. 65535;
type T_Bitfield32 is integer 0 .. 4294967295;
type T_SpeedPpr is integer 1 .. 255;
type T_CANID is integer 0 .. 4294967295;
type T_CANByte is integer 0 .. 255;
type T_CANLength is integer 1 .. 8;
type T_CANChannel is integer 0 .. 3;
type T_CANTxMsg is array [8] of T_CANByte;
type T_CANRxMsg is array [8] of T_CANByte;
type T_CANHandle is integer -128 .. 127;
type T_CANMsgCtr is integer 0 .. 15;
type T_CANkbps is integer 0 .. 1000;
type T_CANMsgCrc is integer 0 .. 255;
type T_HwChannel is integer 0 .. 15;
type T_Counter is integer 0 .. 65535;

const T_Time SYS_dT = 0.005;
  											
sysconst T_Time SY_1ms = 0.001;
sysconst T_Time SY_5ms = 0.005;
sysconst T_Time SY_10ms = 0.01;
sysconst T_Time SY_100ms = 0.1;
  														