#include <iostream>
#include <ctime>
#include "Heap.h"
#include <cstdlib>
#include <sys/time.h> //provides gettimeofday() gives milliseconds
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    double start_time, end_time, interval;
    struct timeval tp; //struct to use with gettimeofday()
    float coefficient = 1;
    int nElements = 2000000;
    int *a = new int[nElements];
    //Load array with random values
    for (int i=0;i<nElements;i++) {
	a[i] = int(rand() % 100);
    }
    Heap heap(nElements);
    //BEGIN timed section
    gettimeofday(&tp,NULL);
    start_time = tp.tv_sec*1000 + tp.tv_usec/1000;
    //Insert values from a into the heap
    for (int i=0;i<nElements;i++) {
	heap.insert(a[i]);
    }
    //Remove values from the heap, insert into array
    for (int i=0;i<nElements;i++) {
	//a[i] = heap.min();
	heap.removeMin();
    }
    //END timed section
    gettimeofday(&tp,NULL);
    end_time = tp.tv_sec*1000+tp.tv_usec/1000;
    interval = end_time - start_time;
    cout << interval << "ms (" << interval/1000 << "s) for " << nElements << " numbers" << endl;
}
