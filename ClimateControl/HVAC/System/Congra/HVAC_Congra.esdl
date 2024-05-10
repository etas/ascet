/**
 * @warning AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
 *
 * @file    HVAC.esdl
 *
 * @author  CGT V0.0
 *
 * @data    7/13/2015 02:36:23 PM
 *
 * @brief   Generated Esdl class from computation HVAC
 *
 */
package System.Congra;


/**
 * Esdl /resource/HVAC/System/HVAC.syq for the system HVAC
 * Source File Path: class
 */
class HVAC_Congra {

	real T_Interior = 0.0;
	real heatFlow_InteriorIntegrated = 0.0;
	real heatFlow_Interior = 0.0;
	characteristic real heatFlowRate_Interior = 0.05;
	real T_Environment = 0.0;
	real heatFlow_Environment = 0.0;
	characteristic real heatFlowRate_Environment = 0.035;
	characteristic real T_Heater = 27.0;
	real heatFlow_Heater = 0.0;
	real heatFlowRate_Heater = 0.0;
	real ventilationRate_Heater = 0.0;
	characteristic real T_Cooler = -8.0;
	real heatFlow_Cooler = 0.0;
	real heatFlowRate_Cooler = 0.0;
	real ventilationRate_Cooler = 0.0;
	real T_Set = 0.0;

	Controller EQ_heaterController;
	Controller EQ_coolingController;

	@no_side_effect public real getT_Interior(){
		return T_Interior;
	}

	public void setT_Interior(real value){
		T_Interior = value;
	}

	@no_side_effect public real getHeatFlow_InteriorIntegrated(){
		return heatFlow_InteriorIntegrated;
	}

	public void setHeatFlow_InteriorIntegrated(real value){
		heatFlow_InteriorIntegrated = value;
	}

	@no_side_effect public real getHeatFlow_Interior(){
		return heatFlow_Interior;
	}

	public void setHeatFlow_Interior(real value){
		heatFlow_Interior = value;
	}

	@no_side_effect public real getHeatFlowRate_Interior(){
		return heatFlowRate_Interior;
	}

	@no_side_effect public real getT_Environment(){
		return T_Environment;
	}

	public void setT_Environment(real value){
		T_Environment = value;
	}

	@no_side_effect public real getHeatFlow_Environment(){
		return heatFlow_Environment;
	}

	public void setHeatFlow_Environment(real value){
		heatFlow_Environment = value;
	}

	@no_side_effect public real getHeatFlowRate_Environment(){
		return heatFlowRate_Environment;
	}

	@no_side_effect public real getT_Heater(){
		return T_Heater;
	}

	@no_side_effect public real getHeatFlow_Heater(){
		return heatFlow_Heater;
	}

	public void setHeatFlow_Heater(real value){
		heatFlow_Heater = value;
	}

	@no_side_effect public real getHeatFlowRate_Heater(){
		return heatFlowRate_Heater;
	}

	public void setHeatFlowRate_Heater(real value){
		heatFlowRate_Heater = value;
	}

	@no_side_effect public real getVentilationRate_Heater(){
		return ventilationRate_Heater;
	}

	public void setVentilationRate_Heater(real value){
		ventilationRate_Heater = value;
	}

	@no_side_effect public real getT_Cooler(){
		return T_Cooler;
	}

	@no_side_effect public real getHeatFlow_Cooler(){
		return heatFlow_Cooler;
	}

	public void setHeatFlow_Cooler(real value){
		heatFlow_Cooler = value;
	}

	@no_side_effect public real getHeatFlowRate_Cooler(){
		return heatFlowRate_Cooler;
	}

	public void setHeatFlowRate_Cooler(real value){
		heatFlowRate_Cooler = value;
	}

	@no_side_effect public real getVentilationRate_Cooler(){
		return ventilationRate_Cooler;
	}

	public void setVentilationRate_Cooler(real value){
		ventilationRate_Cooler = value;
	}

	@no_side_effect public real getT_Set(){
		return T_Set;
	}

	public void setT_Set(real value){
		T_Set = value;
	}


	/* Methods for computations */

	@no_side_effect private real integrate(real inout x, real xdot){
		real step = 1.0;
		x = x + xdot*step;
		return x;
	}

}
