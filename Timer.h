#ifndef TIMER_H
#define TIMER_H

#include <chrono>


using namespace std::chrono;


/*
* A simple timer used to measure running times.
*/
class Timer
{
public:
	// Start the timer.
	inline void start() {
		start_time = system_clock::now();
	}

	// Get the amount of time that passed since last call to start().
	inline long ms_elapsed() {
		auto dur{system_clock::now() - start_time};
		return duration_cast<milliseconds>(dur).count();
	}

private:
	system_clock::time_point start_time;
};

#endif

