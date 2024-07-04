#pragma once
#include <chrono>

namespace Time
{
	/*
	// The TimeService class helps keep track of time in game and calculate delta time.
	// Utilizes the <chrono> library to calculate delta time.
	*/
	class TimeService
	{
	private:
		/*
		// A time point that represents the previous moment in time using the steady clock.
		// The steady clock is a clock that provides a monotonic and constant time source
		// that is not subject to system clock adjustments, making it suitable for measuring
		// time intervals precisely.
		*/
		std::chrono::time_point<std::chrono::steady_clock> previous_time;

		float delta_time;

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:

		void initialize();
		void update();

		float getDeltaTime();
	};
}