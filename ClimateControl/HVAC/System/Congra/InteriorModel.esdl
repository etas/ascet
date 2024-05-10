package System.Congra;


/**
 * Esdl /resource/Example/System/SystemModel.syq for the system InteriorModel
 * Source File Path: class
 */
class InteriorModel {

	real T_env = 0.0;
	real Q_int = 0.0;
	real Q_env = 0.0;
	real Q_heater = 0.0;
	real Q_cooler = 0.0;
	real rate_heater = 0.0;
	real rate_cooler = 0.0;
	real T_int = 0.0;
	real T_set = 0.0;
	real cooler_active = 0.0;
	real heater_active = 0.0;
	characteristic real isolation = 0.01;
	characteristic real T_heater = 27.0;
	characteristic real T_cooler = -8.0;

	PIController ControllerHeater;
	PIController ControllerCooler;

	@no_side_effect public real getT_env(){
		return T_env;
	}

	public void setT_env(real value){
		T_env = value;
	}

	@no_side_effect public real getQ_int(){
		return Q_int;
	}

	public void setQ_int(real value){
		Q_int = value;
	}

	@no_side_effect public real getQ_env(){
		return Q_env;
	}

	public void setQ_env(real value){
		Q_env = value;
	}

	@no_side_effect public real getQ_heater(){
		return Q_heater;
	}

	public void setQ_heater(real value){
		Q_heater = value;
	}

	@no_side_effect public real getQ_cooler(){
		return Q_cooler;
	}

	public void setQ_cooler(real value){
		Q_cooler = value;
	}

	@no_side_effect public real getRate_heater(){
		return rate_heater;
	}

	public void setRate_heater(real value){
		rate_heater = value;
	}

	@no_side_effect public real getRate_cooler(){
		return rate_cooler;
	}

	public void setRate_cooler(real value){
		rate_cooler = value;
	}

	@no_side_effect public real getT_int(){
		return T_int;
	}

	public void setT_int(real value){
		T_int = value;
	}

	@no_side_effect public real getT_set(){
		return T_set;
	}

	public void setT_set(real value){
		T_set = value;
	}

	@no_side_effect public real getCooler_active(){
		return cooler_active;
	}

	public void setCooler_active(real value){
		cooler_active = value;
	}

	@no_side_effect public real getHeater_active(){
		return heater_active;
	}

	public void setHeater_active(real value){
		heater_active = value;
	}

	@no_side_effect public real getIsolation(){
		return isolation;
	}

	@no_side_effect public real getT_heater(){
		return T_heater;
	}

	@no_side_effect public real getT_cooler(){
		return T_cooler;
	}



}
