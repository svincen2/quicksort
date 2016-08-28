proj_name = quicksort
objs = Quicksort.o Insertion_sort.o Util.o main.o

# Commands.
compile = g++ -std=c++11 -c
link = g++ -std=c++11 -o $(proj_name)


$(proj_name): $(objs)
	$(link) $(objs)

Insertion_sort.o: Insertion_sort.h Insertion_sort.cpp
	$(compile) Insertion_sort.cpp

Quicksort.o: Quicksort.h Quicksort.cpp
	$(compile) Quicksort.cpp

Util.o: Util.h Util.cpp
	$(compile) Util.cpp

main.o: main.cpp
	$(compile) main.cpp

clean:
	rm $(objs) $(proj_name)

