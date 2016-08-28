proj_name = tests
include = ../
suite_obj = test_suite.o # Only need to compile this once.
test_objs = Insertion_sort_test.o Quicksort_test.o Random_test.o
deps = ../Quicksort.o ../Insertion_sort.o

compile = g++ -std=c++11 -c -I$(include)
link = g++ -std=c++11 -o $(proj_name) -I$(include)


# Project executable.
$(proj_name): $(suite_obj) $(test_objs)
	$(link) $(suite_obj) $(test_objs) $(deps)


# Test suite.
$(suite_obj): test_suite.cpp
	$(compile) test_suite.cpp


# Tests.
Insertion_sort_test.o: Insertion_sort_test.cpp
	$(compile) Insertion_sort_test.cpp

Quicksort_test.o: Quicksort_test.cpp
	$(compile) Quicksort_test.cpp

Random_test.o: Random_test.cpp
	$(compile) Random_test.cpp


# Helper targets.
clean:
	rm $(test_objs)

