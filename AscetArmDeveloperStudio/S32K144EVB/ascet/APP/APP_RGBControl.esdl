package ascet.APP;
import types.T_Analogue;
import types.T_DutyPercent;
import ascet.Lib.LIB_Rise;
import ascet.Lib.LIB_TimerUp;
import types.SY_1ms;
import types.T_1D_T_Time_T_Intensity;
import types.T_Intensity;
import types.T_Time;
@generated("statemachine", "000000")
type APP_RGBControlStatemachineStates is enum {
	APS_Red,
	APS_Green,
	APS_Blue,
	APS_RGBWithFader
};

class APP_RGBControl {
	@get
	T_DutyPercent APP_RedDuty = 0.0;
	@get
	T_DutyPercent APP_GreenDuty = 0.0;
	@get
	T_DutyPercent APP_BlueDuty = 0.0;
	@set
	boolean APP_Sw2 = false;
	@set
	boolean APP_Sw3 = false;
	@set
	T_Analogue APP_Pot = 0.0;
	LIB_Rise APP_Rise2;
	LIB_Rise APP_Rise3;
	LIB_TimerUp APP_LedTimer;
	T_Intensity APP_GreenIntensity = 0.0;
	characteristic T_1D_T_Time_T_Intensity APP_REDLEDINTENSITY[9] = {{0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}, {0.0, 0.195, 0.293, 0.586, 0.0, 0.0, 0.1, 0.0, 0.0}};
	T_Time APP_LedTime = 0.0;
	characteristic T_1D_T_Time_T_Intensity APP_GREENLEDINTENSITY[9] = {{0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}, {0.586, 0.391, 0.293, 0.0, 0.0, 0.195, 0.195, 0.586, 0.586}};
	T_Intensity APP_BlueIntensity = 0.0;
	characteristic T_1D_T_Time_T_Intensity APP_BLUELEDINTENSITY[9] = {{0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}, {0.0, 0.0, 0.0, 0.0, 0.586, 0.391, 0.391, 0.0, 0.0}};
	T_Intensity APP_RedIntensity = 0.0;
	characteristic T_Time APP_LEDRESETTIME = 8.0;
	T_Intensity APP_RedIntensityMap = 0.0;
	T_Intensity APP_GreenIntensityMap = 0.0;
	T_Intensity APP_BlueIntensityMap = 0.0;
	boolean APP_Run = false;

	@generated("statemachine", "000000")
	public void APP_RGBStateMachineTrig() triggers APP_RGBControlStatemachine;

	@generated("blockdiagram", "ef3404cf")
	private boolean C_AntiClockwise() {
		return APP_Rise3.LIB_Rising(APP_Sw3); // Main/C_AntiClockwise 1
	}

	@generated("blockdiagram", "becde518")
	private boolean C_Clockwise() {
		return APP_Rise2.LIB_Rising(APP_Sw2); // Main/C_Clockwise 1
	}

	@generated("blockdiagram", "13a82309")
	private void A_RGBFader() {
		APP_LedTime = APP_LedTimer.LIB_Time((APP_LedTime >= APP_LEDRESETTIME), SY_1ms); // Main/A_RGBFader 1
		APP_RedIntensityMap = APP_REDLEDINTENSITY.getAt(APP_LedTime); // Main/A_RGBFader 2
		APP_GreenIntensityMap = APP_GREENLEDINTENSITY.getAt(APP_LedTime); // Main/A_RGBFader 3
		APP_BlueIntensityMap = APP_BLUELEDINTENSITY.getAt(APP_LedTime); // Main/A_RGBFader 4
		APP_GreenIntensity = ((APP_GreenIntensityMap * APP_Pot) / 5.0); // Main/A_RGBFader 5
		APP_RedIntensity = ((APP_RedIntensityMap * APP_Pot) / 5.0); // Main/A_RGBFader 6
		APP_BlueIntensity = ((APP_BlueIntensityMap * APP_Pot) / 5.0); // Main/A_RGBFader 7
		APP_RedDuty = (100.0 * APP_RedIntensity); // Main/A_RGBFader 8
		APP_GreenDuty = (100.0 * APP_GreenIntensity); // Main/A_RGBFader 9
		APP_BlueDuty = (100.0 * APP_BlueIntensity); // Main/A_RGBFader 10
	}

	@generated("statemachine", "6c1ecfeb")
	statemachine APP_RGBControlStatemachine default trigger APP_RGBStateMachineTrig using APP_RGBControlStatemachineStates {
		start APS_Red;

		state APS_Red {
			static {
				APP_RedDuty = (APP_Pot * 20.0);
				APP_GreenDuty = 0.0;
				APP_BlueDuty = 0.0;
			}
			transition APP_Rise2.LIB_Rising(APP_Sw2) to APS_Green;
			transition C_AntiClockwise() to APS_RGBWithFader;
		}

		state APS_Green {
			static {
				APP_RedDuty = 0.0;
				APP_GreenDuty = (APP_Pot * 20.0);
				APP_BlueDuty = 0.0;
			}
			transition APP_Rise2.LIB_Rising(APP_Sw2) to APS_Blue;
			transition APP_Rise3.LIB_Rising(APP_Sw3) to APS_Red;
		}

		state APS_Blue {
			static {
				APP_RedDuty = 0.0;
				APP_GreenDuty = 0.0;
				APP_BlueDuty = (APP_Pot * 20.0);
			}
			transition APP_Rise3.LIB_Rising(APP_Sw3) to APS_Green;
			transition C_Clockwise() to APS_RGBWithFader;
		}

		state APS_RGBWithFader {
			static {
				A_RGBFader();
			}
			transition C_Clockwise() to APS_Red;
			transition C_AntiClockwise() to APS_Blue;
		}
	}
}