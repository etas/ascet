package enumerations;
	
type H_Status is enum{
	H_Init, H_Okay, H_OverValue, H_UnderValue, H_RateHigh, H_Implausible, H_Timeout
};

type LB_RiseFall is enum
{
	LB_Unchanged, LB_Rise, LB_Fall
};

type S32K144_Gpio is enum {
PortA_0, PortA_1, PortA_2, PortA_3, PortA_4, PortA_5, PortA_6, PortA_7, PortA_8, PortA_9, PortA_10, PortA_11, PortA_12, PortA_13, PortA_14, PortA_15, PortA_16, PortA_17, 	
PortB_0, PortB_1, PortB_2, PortB_3, PortB_4, PortB_5, PortB_6, PortB_7, PortB_8, PortB_9, PortB_10, PortB_11, PortB_12, PortB_13, PortB_14, PortB_15, PortB_16, PortB_17, 	
PortC_0, PortC_1, PortC_2, PortC_3, PortC_4, PortC_5, PortC_6, PortC_7, PortC_8, PortC_9, PortC_10, PortC_11, PortC_12, PortC_13, PortC_14, PortC_15, PortC_16, PortC_17, 	
PortD_0, PortD_1, PortD_2, PortD_3, PortD_4, PortD_5, PortD_6, PortD_7, PortD_8, PortD_9, PortD_10, PortD_11, PortD_12, PortD_13, PortD_14, PortD_15, PortD_16, PortD_17, 	
PortE_0, PortE_1, PortE_2, PortE_3, PortE_4, PortE_5, PortE_6, PortE_7, PortE_8, PortE_9, PortE_10, PortE_11, PortE_12, PortE_13, PortE_14, PortE_15, PortE_16 		
};