package ACC_AUTOSAR;
import ACC.ACC_SWC;
import interfaces.sri_bsw2asw;
import interfaces.sri_asw2bsw;
import interfaces.sri_asw2asw;

@ArApplicationSoftwareComponent
singleton class ACC_AR {
	ACC_SWC ACC_instance;
	@ArRequiredPortPrototype
	sri_bsw2asw rp_bsw2asw;
	@ArProvidedPortPrototype
	sri_asw2bsw pp_asw2bsw;
	@ArRequiredPortPrototype
	sri_asw2asw rp_asw2asw;

	@ArRunnable
	@ArInitEvent(name = "asd_event_acc_ini")
	@generated("blockdiagram", "cac9a204")
	public void ACC_runnable_ini() {
		ACC_instance.proc_ini(); // ACC_runnable_spec/ACC_runnable_ini 1
	}

	@ArRunnable
	@ArTimingEvent(name = "asd_event_acc_10ms", period = 0.01)
	@generated("blockdiagram", "cbb3a948")
	public void ACC_runnable_10ms() {
		ACC_instance.proc_10ms(); // ACC_runnable_spec/ACC_runnable_10ms 1
	}
}