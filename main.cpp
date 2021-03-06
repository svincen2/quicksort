#include "Insertion_sort.h"
#include "Quicksort.h"
#include "Random.h"
#include "Util.h"
#include <iostream>
#include <vector>


/*
* Investigate the running time of a variation of quicksort.
* params:
*	pivot - Function to select the pivot value.
*	partition - Function to partition a range.
*	vec - Vector of random integers.
*	sorter - Quicksort instance which will sort the vector.
*/
void investigate(Quicksort::Pivot_func pivot,
				 Quicksort::Partition_func partition,
				 const std::vector<int>& vec,
				 Quicksort& sorter)
{
	std::vector<int> vec_copy{vec};
	sorter.set_partition_func(partition);
	sorter.set_pivot_func(pivot);
	long elapsed = time([sorter, &vec_copy]() {
		sorter.sort(vec_copy, 0, vec_copy.size());
	});
	std::cout << "time(ms):  " << elapsed << '\n';
}


/*
* Investigates the effects on efficiency of variations to quicksort.
* Items investigated:
* - Choosing a pivot value:
*	- Always choose first element.
*	- Choose a median of the first, middle, and last elements.
* - Partitioning:
*	- Sweep from both ends.
*	- Sweep from the 'left' only.
* - Finish with insertion sort:
*	- Find optimal time to switch to insertion sort.
* params:
*	max - Maximum value of a randomly generated integer.
*	size - Size of the list to sort.
*/
void investigate_quicksort_variations(const int max, const int size)
{
	Random<int> rnd{1, max};
	std::vector<int> vec{rnd.vector(size)};

	Quicksort sorter{};
	std::cout << "Lomuto partition, pivot: first, random, median\n";
	investigate(&pivot_first_element, &lomuto_partition, vec, sorter);
	investigate(&pivot_random_element, &lomuto_partition, vec, sorter);
	investigate(&pivot_median_of_three, &lomuto_partition, vec, sorter);

	std::cout << "Hoare partition, pivot: first, random, median\n";
	investigate(&pivot_first_element, &hoare_partition, vec, sorter);
	investigate(&pivot_random_element, &hoare_partition, vec, sorter);
	investigate(&pivot_median_of_three, &hoare_partition, vec, sorter);

	std::cout << "Switch to insertion sort.\n";
	for (int i = 5; i < 30; ++i) {
		std::cout << "threshold: " << i << ", ";
		sorter.set_threshold(i);
		investigate(&pivot_first_element, &hoare_partition, vec, sorter);
	}
}


/*
* Main entry point into the program.
*/
int main(int argc, char* argv[])
{
	try {
		int int_max{std::stoi(argv[1])};
		int array_size{std::stoi(argv[2])};
		investigate_quicksort_variations(int_max, array_size);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}
	return 0;
}
