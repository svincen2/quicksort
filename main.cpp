#include "Insertion_sort.h"
#include "Quicksort.h"
#include "Util.h"
#include <iostream>
#include <vector>


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
*/
void investigate_quicksort_variations()
{
	srand(26); // Seed random for testing.
	std::vector<int> vec{random_vec_of_size(100000, 100)};
	long elapsed{};

	Quicksort sorter{};
	elapsed = time([sorter, &vec]() {
		sorter.sort(vec, 0, vec.size());
	});
	std::cout << "time (ms): " << elapsed << '\n';
}


/*
* Main entry point into the program.
*/
int main()
{
	try {
		investigate_quicksort_variations();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return -1;
	}
	return 0;
}

