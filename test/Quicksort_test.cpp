#include "catch.hpp"
#include "Quicksort.h"
#include "Random.h"
#include <iostream>
#include <vector>


SCENARIO("Sorting with quicksort") {
	GIVEN("A vector of random integers") {
		Random<int> rnd{1, 100};
		rnd.seed(26);
		std::vector<int> vec{rnd.vector(100)};
		WHEN("Sorted using quicksort") {
			Quicksort sorter{};
			sorter.sort(vec, 0, vec.size());
			THEN("The vector is sorted in ascending order") {
				for (int i = 0; i != vec.size() - 1; ++i) {
					REQUIRE(vec[i] <= vec[i + 1]);
				}
			}
		}
	}
}
