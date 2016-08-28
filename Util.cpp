#include "Util.h"


/*
* Generate a vector of random numbers in the range[0, max),
* with the given number of elements.
* params:
*	n - Number of elements of resulting vector.
*	    For example, n == 5 yields a vector with 5 random ints.
*	max - Maximum bound of random number.
*/
std::vector<int> random_vec_of_size(int n, int max)
{
	std::vector<int> vec{};
	for (int i = 0; i != n; ++i) {
		vec.push_back(rand() % max);
	}
	return vec;
}

