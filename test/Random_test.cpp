#include "catch.hpp"
#include "Random.h"

#include <iostream>


SCENARIO("Generating random integers") {
	GIVEN("A random number generator") {
		Random<int> rnd{0, 9};
		WHEN("Generating a vector of random integers") {
			std::vector<int> vec{rnd.vector(1000)};
			THEN("All integers are in range") {
				for (auto p = vec.begin(); p != vec.end(); ++p) {
					REQUIRE(*p >= rnd.min());
					REQUIRE(*p <= rnd.max());
				}
			}
			THEN("All possible values are represented at least once") {
				std::vector<int> counts(10, 0);
				for (auto p = vec.begin(); p != vec.end(); ++p) {
					counts[*p]++;
				}
				for (int i = 0; i != counts.size(); ++i) {
					REQUIRE(counts[i] > 0);
				}
			}
		}
	}
}
