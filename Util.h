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


/*
* Print the given vector on a single line, separated by commas.
* params:
*	vec - Vector to print.
*	os - Output stream to print to.
*/
template<typename T>
void print_vector(std::vector<T>& vec, std::ostream& os)
{
	for (auto p = vec.begin(); p != vec.end(); ++p) {
		os << *p;
		if (p + 1 != vec.end()) os << ", ";
	}
	os << '\n';
}

#endif

