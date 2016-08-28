#include "catch.hpp"
#include "Insertion_sort.h"


SCENARIO("Insertion sorting a vector of ints") {
	GIVEN("The vector: (4, 6, -2, 8, 7, -8, 10, 1, 2, 5)") {
		std::vector<int> vec{4, 6, 2, 8, 7, 8, 10, 1, 2, 5};
		WHEN("Sorting with insertion sort") {
			insertion_sort(vec);
			THEN("Vector is sorted in ascending order") {
				REQUIRE(vec.size() == 10);
				for (int i = 0; i < vec.size() - 1; ++i) {
					REQUIRE(vec[i] <= vec[i + 1]);
				}
			}
		}
	}
}
