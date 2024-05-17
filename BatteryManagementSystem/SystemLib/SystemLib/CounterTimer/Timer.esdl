package SystemLib.CounterTimer;

import SystemLib.Miscellaneous.DeltaTimeService;

/** Timer decrements the time counter by dT and signals when the time counter has reached zero. It is not retriggerable. */
class Timer {
	real timeCounter = 0.0;

	/** The time counter is decremented by dT. */
	@generated("blockdiagram", "68d376fb")
	public void compute() {
		timeCounter = max((timeCounter - DeltaTimeService.deltaT), 0.0); // Main/compute 1
	}

	/** TRUE is returned if the time counter value is greater than zero. Otherwise, FALSE is returned. */
	@no_side_effect
	@generated("blockdiagram", "cc9a6cb6")
	public boolean isElapsed() {
		return(timeCounter <= 0.0); // Main/isElapsed 1
	}

	/** The time counter is set to startTime if the time counter value was previously less than or equal to zero. */
	@generated("blockdiagram", "9498627d")
	public void begin(real in startTime) {
		timeCounter = startTime; // Main/begin 1
	}
}