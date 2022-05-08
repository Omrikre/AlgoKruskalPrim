#pragma once
#include "Pair.h" 
#include <iostream>
using namespace std;

class Heap {
protected:
    // members:
    Pair** array; // pointer to array of elements in heap
    int maxSize; // maximum possible size of min heap
    int currSize; // Current number of elements in min heap

    // methods: (private)
    int parent(int i) { return (i - 1) / 2; }   // to get index of the parent of node at index i
    int left(int i) { return (2 * i + 1); }     // to get index of left child of node at index i
    int right(int i) { return (2 * i + 2); }    // to get index of right child of node at index i
	virtual ~Heap();
    // must inplement in max/min heap
    virtual void fixHeap(int curr) = 0;
    virtual void fixInsert(int index) = 0;
    virtual void swap(Pair* x, Pair* y) = 0;
    virtual void deletePairByIndex(int ind) = 0; // delete pair from Heap by index

	
public:
    // methods: (public)
    Heap() : array(nullptr), maxSize(0), currSize(0) {} // defult c'tor
    int getCurrSize() { return currSize; } // return the cuurent size of heap
    

    // must inplement in max/min heap
    virtual void insertKey(Pair* k) = 0; // Inserts a new key 'k'


};