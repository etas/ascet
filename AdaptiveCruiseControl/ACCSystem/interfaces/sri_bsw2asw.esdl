package interfaces;
import common_esdl.c;

@ArSenderReceiverInterface
type sri_bsw2asw is struct {
	c Actual_Velocity_LC;
	c Actual_Velocity_EC;
	c Actual_Position_EC;
	c Set_Velocity;
};
