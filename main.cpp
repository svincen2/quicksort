#include "Insertion_sort.h"
#include "Quicksort.h"
#include "Random.h"
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
	Random<int> rnd{-10, 10};
	
	std::vector<int> vec{rnd.vector(10)};
	print_vector(vec, std::cout);
	long elapsed{};

	Quicksort sorter{};
	elapsed = time([sorter, &vec]() {
		sorter.sort(vec, 0, vec.size());
	});
	print_vector(vec, std::cout);
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

