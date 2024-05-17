package SOCClasses;

import formulas.f_0p01;
import formulas.f_2e7;
import formulas.f_0p001;
import formulas.OneToOne;
import formulas.f_2e12;
import SystemLib.Nonlinears.Limiter;

type T_BATT_VOLT is real 0.0 .. 5.0 delta 0.001953125; // = 1/512
type T_SINT8 is integer using sint8;

class AccuCharacteristic {

	characteristic T_BATT_VOLT BaseVoltage = 1.4;
	characteristic real GainVoltage = 0.001;
	characteristic real GainVoltage_inv <- "0.1/x", x = GainVoltage;
	characteristic curve_real temp_curve[16] = {
		{ 213.15, 223.15, 233.15, 243.15, 253.15, 263.15, 273.15, 283.15, 293.15, 303.15, 313.15, 323.15, 333.15,
			343.15, 353.15, 363.15 },
		{ 0.65, 0.63, 0.6, 0.5, 0.35, 0.23, 0.17, 0.15, 0.15, 0.15, 0.16, 0.16, 0.165, 0.17, 0.19, 0.24 }
	};
	Limiter Limiter_instance;

	@generated("blockdiagram", "fb6d9866")
	public real calc(real in U, real in T) {
		return Limiter_instance.value(0.0, ((Limiter_instance.value(1.45, (U + temp_curve.getAt(T)), 2.05) - BaseVoltage) * GainVoltage_inv), 100.0); // SOC_spec/calc 1
	}

	public initializer NewBattery() {
		BaseVoltage = 1.45;
		GainVoltage = 0.0006;
	}

	public initializer HundredChargeCycles() {
		BaseVoltage = 1.1;
		GainVoltage = 0.0002;
	}
	representation SOC1 {
		represent GainVoltage using {
			formula = f_0p001;
			datatype = uint16;
		};
		represent GainVoltage_inv using {
			formula = OneToOne;
			datatype = uint16;
		};
		represent temp_curve using Temperature_raw_dec -> Voltage_raw_dec;
		represent calc.U using Voltage_raw_dec;
		represent calc.T using Temperature_raw_dec;
		represent calc return using {
			formula = f_0p01;
			datatype = uint16;
		};
	}
	representation SOC2 {
		represent GainVoltage using {
			formula = f_2e12;
			datatype = uint8;
		};
		represent GainVoltage_inv using {
			formula = OneToOne;
			datatype = uint16;
		};
		represent temp_curve using Temperature_raw_bin -> Voltage_raw_bin;
		represent calc.U using Voltage_raw_bin;
		represent calc.T using Temperature_raw_bin;
		represent calc return using {
			formula = f_2e7;
			datatype = uint16;
		};
	}
}

representation Voltage_raw_dec {
	datatype = sint16;
	formula = f_0p01;
}

representation Voltage_raw_bin {
	datatype = sint16;
	formula = f_2e12;
}

representation Temperature_raw_dec {
	datatype = uint16;
	formula = f_0p01;
}

representation Temperature_raw_bin {
	datatype = uint16;
	formula = f_2e7;
}