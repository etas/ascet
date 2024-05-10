package System.Congra;


/**
 * Esdl /resource/Example/System/SystemModel.syq for the system PIController
 * Source File Path: struct type
 */
  type PIController is struct{
	real P;
	real I;
	real difference;
	real difference_dot;
};
