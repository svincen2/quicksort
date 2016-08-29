#include "Insertion_sort.h"
#include "Quicksort.h"
#include "Random.h"
#include <algorithm> // For swap.
#include <tuple>


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
	Random<int> rnd{begin, end - 1};
	std::swap(vec[begin], vec[rnd.value()]);
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
	auto cmp{[](std::tuple<int, int>& a, std::tuple<int, int>& b) {
		return std::get<1>(a) <= std::get<1>(b);
	}};

	int mid{begin + (end - begin) / 2};
	std::vector<std::tuple<int, int>> samples{};
	samples.push_back(std::tuple<int, int>{begin, vec[begin]});
	samples.push_back(std::tuple<int, int>{mid, vec[mid]});
	samples.push_back(std::tuple<int, int>{end - 1, vec[end - 1]});
	std::sort(samples.begin(), samples.end(), cmp);
	std::swap(vec[begin], vec[std::get<0>(samples[1])]);
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
			// Assumes pivot is always first element.
			std::swap(vec[j], vec[begin]);
		}
	}
	return j;
}


/*
* Needs implementation
*/
int lumotu_partition(std::vector<int>&vec, int begin, int end, int pivot_value)
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

