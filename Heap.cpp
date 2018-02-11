#include <iostream>
#include "Heap.h"

using namespace std;
Heap::Heap(int n){
    element_size = 1;
    array_size = n;
    a = new int[array_size];
}

Heap::~Heap(){
    delete [] a;
}

//number of elements
int Heap::size() const{
    return element_size;
}

// is the queue empty?
bool Heap::empty() const{
    return element_size == 1;
}

//insert element
void Heap::insert(const int& e) {
    if (empty()) {
	a[1] = e;
	element_size += 1;
    }
    else {
	if (element_size <= array_size) {
	    a[element_size] = e;
	    int old_index = element_size;
	    element_size += 1;
	    heapup(old_index);
	}
    }
    //printHeap();
}

//return minimum element
int Heap::min() {
    if (!empty()) {return a[1];}
    else {return -1;}
}

//remove minimum
void Heap::removeMin() {
    a[1] = a[element_size-1];
    element_size -= 1;
    heapdown(1);
    //printHeap();
}

void Heap::heapup(int inserted_index) {
    int parent_index;
    if (inserted_index == 1) {return;}
    if (inserted_index % 2 == 0) {
	parent_index = inserted_index/2;
    }
    else {
	parent_index = (inserted_index - 1)/2;
    }
    if (a[inserted_index] >= a[parent_index]) {
	return;
    }
    else {
	int temp = a[inserted_index];
	a[inserted_index]=a[parent_index];
	a[parent_index] = temp;
	heapup(parent_index);
    }
}

void Heap::heapdown(int root_index) {
    int left_child_index, right_child_index;
    //When both children exist
    if (element_size > 2*root_index+1) {
	right_child_index = 2*root_index+1;
	left_child_index = 2*root_index;
	//When right child is larger
	if (a[left_child_index] >= a[right_child_index] && a[root_index] > a[right_child_index]) {
	    int temp = a[root_index];
	    a[root_index] = a[right_child_index];
	    a[right_child_index] = temp;
	    heapdown(right_child_index);
	}
	//When left child is larger
	else if (a[left_child_index] < a[right_child_index] && a[root_index] > a[left_child_index]) {
	    int temp = a[root_index];
	    a[root_index] = a[left_child_index];
	    a[left_child_index] = temp;
	    heapdown(left_child_index);
	}
    }
    //When one child exists
    else if (element_size > 2*root_index) {
	left_child_index = 2*root_index;
	if (a[left_child_index] < a[root_index]) {
	    int temp = a[root_index];
	    a[root_index] = a[left_child_index];
	    a[left_child_index] = temp;
	}
    }
}

void Heap::printHeap() {
    for (int i=1;i<element_size;i++) {
	cout << a[i] << ",";
    }
    cout << endl;
}
