main:	main.cpp Heap.o
	g++ main.cpp Heap.o

Heap:	Heap.h Heap.cpp
	g++ -c Heap.cpp

clean:
	rm -f *.o a.out
