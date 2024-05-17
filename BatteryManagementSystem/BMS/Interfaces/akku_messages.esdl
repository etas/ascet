package Interfaces;

import formulas.f_2e7;
import SOCClasses.Temperature_raw_bin;
import SOCClasses.Voltage_raw_bin;
import formulas.f_0p01;
import formulas.f_0p001;
import SOCClasses.Temperature_raw_dec;
import SOCClasses.Voltage_raw_dec;

data interface akku_messages using SOC2 {
	real voltage = 0.0;
	real SOC_estimated = 0.0;
	real SOC_model;
	real T_ambient = 290.0;
	real T_Cell = 290.0;
	real current = 0.0;
	boolean SOC_low = false;
	S32 SOC_symbol = 0;
	representation SOC1 {
		represent voltage using Voltage_raw_bin;
		represent SOC_estimated using {
			formula = f_0p01;
			datatype = uint16;
		};
		represent T_Cell using Temperature_raw_dec;
		represent current using {
			formula = f_0p001;
			datatype = sint16;
		};
		represent T_ambient using Temperature_raw_dec;
	}
	representation SOC2 {
		represent voltage using Voltage_raw_dec;
		represent SOC_estimated using {
			formula = f_2e7;
			datatype = uint16;
		};
		represent current using {
			formula = f_2e7;
			datatype = sint16;
		};
		represent T_Cell using Temperature_raw_bin;
		represent T_ambient using Temperature_raw_bin;
	}
}