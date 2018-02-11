#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;
class Heap {

public:

Heap(int n);
~Heap();
int size() const;  //number of elements
bool empty() const; // is the queue empty?
void insert(const int&); //insert element
int min(); //minimum element
void removeMin(); //remove minimum
void printHeap(); //Print the array of the heap

private:

// allocates an array to store elements
int *a;

//
int element_size;

int array_size;

//Note: should only be called when element_size < array_size
void heapup(int);

void heapdown(int);

};
#endif
