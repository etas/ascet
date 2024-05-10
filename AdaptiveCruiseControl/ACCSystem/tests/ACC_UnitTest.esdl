package tests;

import ACC.ACC_SWC;
import VehicleModel.VehicelDynamicModel.Vehicle0;
import VehicleModel.RelativeData.RelativeData;
import interfaces.messages;
import time.DeltaTimeAccess;
import assert.Assert;
import SystemLib.Miscellaneous.DeltaTimeService;

type loopCounter1000 is integer 0 .. 99999;
type loopCounter10 is integer 0 .. 6999;

singleton class ACC_UnitTest

reads messages.Relative_Distance, messages.Actual_Velocity_EC
writes messages.Set_Velocity, messages.Actual_Velocity_LC {

	ACC_SWC TestACCInst;
	Vehicle0 TestVehModel;
	RelativeData RelDataInst;
	DeltaTimeAccess DeltaTimeAccess_instance;
	Assert Assert;
	DeltaTimeService DeltaTimeService_instance;

	@Before
	public void init() {
		RelDataInst.proc_ini();
		TestACCInst.proc_ini();
		RelDataInst.SetDistance100(); // Initial vehicle distance is always 100 meters 
	}

	@Test
	public void test1_KeepDistance() { // Test constant ACC traveling
		DeltaTimeAccess_instance.setDeltaTime(0.01);
		messages.Set_Velocity = 100.0; // Out own ACC set speed in 100 km/h
		messages.Actual_Velocity_LC = 80.0; // Vehicle in front (LC) speed is 80 km/h
		for (i in loopCounter1000) {
			TestVehModel.calc();
			TestACCInst.proc_10ms();
			RelDataInst.proc_10ms();
			RelDataInst.AntiOverFlow_10ms();
			Assert.expectGreaterThanOrEqual(messages.Relative_Distance, 100.0); // Check cyclic if distance between vehicles is always more than 100 m
		}
		Assert.assertGreaterThanOrEqual(messages.Relative_Distance, 120.0); // Check if final distance between vehicles is more than 120 m

	}

	@Test
	public void test2_DecelToStandstill() { // Here we test ACC control when vehicle in front slows down to stand still
		DeltaTimeAccess_instance.setDeltaTime(0.01);
		messages.Set_Velocity = 55.0; // ACC set spedd in 55 km/h
		messages.Actual_Velocity_LC = 30.0; // Vehicle in front (LC) speed is 30 km/h
		for (i in loopCounter1000) // We travel for 1000 sec in ACC mode
		{
			TestVehModel.calc();
			TestACCInst.proc_10ms();
			RelDataInst.proc_10ms();
			RelDataInst.AntiOverFlow_10ms();
		}

		messages.Actual_Velocity_LC = 0.0; // After 1000 sec ACC controlled traveling Vehicle in front (LC) stops
		for (j in loopCounter10) {
			TestVehModel.calc();
			TestACCInst.proc_10ms();
			RelDataInst.proc_10ms();
			RelDataInst.AntiOverFlow_10ms();
			Assert.expectGreaterThanOrEqual(messages.Relative_Distance, 10.0);
		} // Check cyclic if distance less than 10 m between vehicles
		Assert.assertLessThanOrEqual(messages.Actual_Velocity_EC, 0.04); // Check if own vehicle slows down to stand still after 70 sec
	}

	@Test
	public void test3_KeepACCSetSpeed() { // Here we test keeping the ACC set speed when vehicle in front runs away
		DeltaTimeAccess_instance.setDeltaTime(0.01);
		messages.Set_Velocity = 85.0; // Our ACC set speed in 85 km/h
		messages.Actual_Velocity_LC = 80.0; // Vehicle in front (LC) speed is 80 km/h
		for (i in loopCounter1000) // We travel for 1000 sec in ACC mode
		{
			TestVehModel.calc();
			TestACCInst.proc_10ms();
			RelDataInst.proc_10ms();
			RelDataInst.AntiOverFlow_10ms();
		}

		messages.Actual_Velocity_LC = 180.0; // Now Vehicle in front (LC) speeds up faster than our set speed
		for (j in loopCounter1000) // We travel again for 1000 sec in ACC mode
		{
			TestVehModel.calc();
			TestACCInst.proc_10ms();
			RelDataInst.proc_10ms();
			RelDataInst.AntiOverFlow_10ms();
			Assert.expectLessThanOrEqual(messages.Actual_Velocity_EC, 86.0); // Check if own speed never exeeds 86 km/h}
		}

	}
}