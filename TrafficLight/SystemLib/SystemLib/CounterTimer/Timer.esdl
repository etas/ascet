package SystemLib.CounterTimer;

import SystemLib.Miscellaneous.DeltaTimeService;

/** Timer decrements the time counter by dT and signals when the time counter has reached zero. */
class Timer {

	real timeCounter = 0.0;

	/** The time counter is decremented by dT. */
	@generated("blockdiagram", "e58d862e")
	public void compute() {
		timeCounter = max((timeCounter - DeltaTimeService.deltaT), 0.0); // Main/compute 1
	}

	/** TRUE is returned if the time counter value is greater than zero. Otherwise, FALSE is returned. */
	@no_side_effect
	@generated("blockdiagram", "b8d93128")
	public boolean isElapsed() {
		return(timeCounter <= 0.0); // Main/isElapsed 1
	}

	/** The time counter is set to startTime if the time counter value was previously less than or equal to zero. */
	@generated("blockdiagram", "cda4f595")
	public void begin(real in startTime) {
		timeCounter = startTime; // Main/begin 1
	}

	@no_side_effect
	@generated("blockdiagram", "e9032247")
	public real getTime() {
		return timeCounter; // Main/getTime 1
	}
}