#include "Insertion_sort.h"
#include <algorithm>


/*
* Insertion sort algorithm.
* params:
*	vec - Vector of ints.
*/
void insertion_sort(std::vector<int>& vec)
{
	for (int i = 1; i != vec.size(); ++i) {
		for (int j = i; j > 0; --j) {
			if (vec[j] < vec[j - 1]) {
				std::swap(vec[j], vec[j - 1]);
			}
			else {
				break; 
			}
		}
	}
}

