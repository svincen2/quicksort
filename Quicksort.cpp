#include "Insertion_sort.h"
#include "Quicksort.h"
#include "Random.h"
#include <algorithm> // For swap.
#include <cstdlib>   // For rand.


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
* The pivot value will be placed in first position of the given vector.
* params:
*	vec - Vector of ints.
*	begin - Beginning of range.
*	end - One past end of range (unused).
* return:
*	int - The pivot value.
*/
long pivot_random_element(std::vector<int>& vec, int begin, int end)
{
	std::swap(vec[begin], vec[begin + (rand() % (end - begin))]);
	return vec[begin];
}


/*
* Use the median of the first, last, and middle element in the
* given vector as the pivot value.
* Once found, the pivot value will be placed in the first position of
* the given vector.
* params:
*	vec - Vector of ints.
* return:
*	long - The pivot value.
*/
long pivot_median_of_three(std::vector<int>& vec, int begin, int end)
{
	int pivot_index{};
	int middle{begin + (end - begin) / 2};
	int last{end - 1};
	if (vec[begin] <= vec[middle] && vec[begin] <= vec[last]) {
		// First is smallest, return min of middle, last
		if (vec[middle] <= vec[last]) {
			pivot_index = middle;
		}
		else {
			pivot_index = last;
		}
	}
	else if (vec[begin] >= vec[middle] && vec[begin] >= vec[last]) {
		// First is largest, return max of middle, last.
		if (vec[middle] >= vec[last]) {
			pivot_index = middle;
		}
		else {
			pivot_index = last;
		}
	}
	else {
		// First is the median.
		pivot_index = begin;
	}
	std::swap(vec[begin], vec[pivot_index]);
	return vec[begin];
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
			std::swap(vec[j], vec[begin]);
		}
	}
	return j;
}


/*
* Partition the range [begin, end) based on the pivot value,
* moving from the 'left' or lower end of the range only.
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
int lomuto_partition(std::vector<int>&vec, int begin, int end, int pivot_value)
{
	int split{begin};
	for (int i = begin + 1; i != end; ++i) {
		if (vec[i] < pivot_value) {
			std::swap(vec[++split], vec[i]);
		}
	}
	std::swap(vec[begin], vec[split]);
	return split;
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
	int count{end - begin};
	if (count <= 1) return;
	if (count <= threshold) {
		insertion_sort(vec, begin, end);
	}
	else {
		long pivot_value{pivot(vec, begin, end)};
		int split{partition(vec, begin, end, pivot_value)};
		sort(vec, begin, split);
		sort(vec, split + 1, end);
	}
}
