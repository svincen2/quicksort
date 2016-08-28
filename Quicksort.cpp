#include "Quicksort.h"
#include "Insertion_sort.h"
#include <cstdlib> // For rand()


/* Pivot function definitions. */

/*
* Use the first element in the vector as the pivot value.
* params:
*	vec - Vector of ints.
*	begin - Beginning of range.
*	end - One past end of range (unused).
* return:
*	int - The pivot value.
*/
long pivot_first_element(std::vector<int>& vec, int begin, int end)
{
	return vec[begin];
}


/*
* Use a random element in the vector as the pivot value.
* params:
*	vec - Vector of ints.
*	begin - Beginning of range.
*	end - One past end of range (unused).
* return:
*	int - The pivot value.
*/
long pivot_random_element(std::vector<int>& vec, int begin, int end)
{
	return vec[begin + (rand() % (end - begin))];
}


/*
* Use the median of the first, last, and middle element in the
* given vector as the pivot value.
* params:
*	vec - Vector of ints.
* return:
*	long - The pivot value.
*/
long pivot_median_of_three(std::vector<int>& vec, int begin, int end)
{
	long first{vec[begin]};
	long middle{vec[begin + ((end - begin) / 2)]};
	long last{vec[end - 1]};
	return (first + middle + last) / 3;
}


/* Partitioning function definitions. */

/*
* Partition the range [begin, end) based on the pivot value,
* moving from both ends of the range.
* params:
*	begin - Index of first element in the range.
*	end - Index of one past the last element in the range.
*	pivot_value - The value used to partition the range.
* return:
*	int - Index of the mid-point of the partition.
*	      Everything before this point will be less than the
*	      pivot value.
*	      Everything after this point will be greater or equal
*	      to the pivot value.
*/
int hoare_partition(std::vector<int>& vec,
						 int begin,
						 int end,
						 int pivot_value)
{
	int i{begin};
	int j{end};
	while (i < j) {
		while ((++i < vec.size()) && (vec[i] < pivot_value));
		while ((--j > 0) && (vec[j] > pivot_value));
		if (i < j) {
			std::swap(vec[i], vec[j]);
		}
		else if (i >= j) {
			// Assumes pivot was first element.
			std::swap(vec[j], vec[begin]);
		}
	}
	return j;
}


int lumotu_partition(std::vector<int>&vec, int begin, int end, int pivot_value)
{
	// Needs implementation.
}



/* Quicksort member function definitions. */

/*
* Construct a Quicksort with
* default pivot and partitioning functions,
* and a seemingly unreachable threshold.
*/
Quicksort::Quicksort()
	: pivot{&pivot_first_element},
	  partition{&hoare_partition},
	  threshold{0}
{
}


/*
* Quicksort the given vector using the current
* pivot and partitioning functions (stored as members).
* params:
*	vec - Vector of integers to sort.
*/
void Quicksort::sort(std::vector<int>& vec, int begin, int end) const
{
	if (begin >= end - 1) return;
	if (vec.size() <= threshold) {
		insertion_sort(vec);
	}
	else {
		long pivot_value{pivot(vec, begin, end)};
		int split{partition(vec, begin, end, pivot_value)};
		sort(vec, begin, split);
		sort(vec, split + 1, end);
	}
}

