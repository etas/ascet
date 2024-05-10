package SENSED_DATA_AUTOSAR;
import SENSED_DATA.Sensed_Data_SWC;
import interfaces.sri_bsw2asw;
import interfaces.sri_asw2asw;
import interfaces.sri_ActPos_LC;

@ArApplicationSoftwareComponent
singleton class Sensed_Data_AR {
	Sensed_Data_SWC Sensed_Data_instance;
	@ArRequiredPortPrototype
	sri_bsw2asw rp_bsw2asw;
	@ArProvidedPortPrototype
	sri_asw2asw pp_asw2asw;
	@ArRequiredPortPrototype
	sri_ActPos_LC rp_bsw2asw_ActPos_LC;

	@ArRunnable
	@ArInitEvent(name = "asd_event_sd_ini")
	@generated("blockdiagram", "7b88b319")
	public void SD_runnable_ini() {
		Sensed_Data_instance.proc_ini(); // SD_runnable_spec/SD_runnable_ini 1
	}

	@ArRunnable
	@ArTimingEvent(name = "asd_event_sd_10ms", period = 0.01)
	@generated("blockdiagram", "fa4fb474")
	public void SD_runnable_10ms() {
		Sensed_Data_instance.proc_10ms(); // SD_runnable_spec/SD_runnable_10ms 1
	}
}