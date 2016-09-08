#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>


// Various ways to select the pivot value.
long pivot_first_element(std::vector<int>&, int, int);
long pivot_random_element(std::vector<int>&, int, int);
long pivot_median_of_three(std::vector<int>&, int, int);


// Various ways to partition the vector.
int hoare_partition(std::vector<int>&, int, int, int);
int lomuto_partition(std::vector<int>&, int, int, int);
	

/*
* Quicksort algorithm that is parameterized as follows:
* - Selecting pivot value.
* - Partitioning the vector.
* - Partition 'threshold'.
* The partition 'threshold' dictates how many partitions must be created
* before the algorithm will switch over to insertion sort to finish sorting.
*/
class Quicksort
{
public:
	// Aliases for pointers to functions.
	using Pivot_func = long(*)(std::vector<int>&, int, int);
	using Partition_func = int(*)(std::vector<int>&, int, int, int);

	// Constructor.
	Quicksort();

	// Quicksort a vector.
	void sort(std::vector<int>&, int, int) const;

	// Mutators.
	void set_pivot_func(Pivot_func p) { pivot = p; }
	void set_partition_func(Partition_func p) { partition = p; }
	void set_threshold(int t) { threshold = t; }

private:
	// Functions used in the quicksort algorithm.
	Pivot_func pivot;
	Partition_func partition;

	// Number of iterations of quicksort before switching to insertion sort.
	int threshold;
};

#endif
