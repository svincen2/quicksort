#ifndef UTIL_H
#define UTIL_H

#include <ostream>
#include <vector>
#include "Timer.h"


/*
* Time the execution of the given function.
* params:
*	func - Function to execute.
*/
template<typename T>
long time(T func)
{
	Timer t{};
	t.start();
	func();
	return t.ms_elapsed();
}

#endif
