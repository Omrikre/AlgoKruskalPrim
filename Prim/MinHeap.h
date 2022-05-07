#pragma once
#include "Heap.h"

class MinHeap : public Heap {
private:
    // methods: (private)
    void fixHeap(int curr);
    void fixInsert(int index);

public:
    MinHeap(int arrSize);
    MinHeap() {}

    Pair* GetMin() { return array[0]; } // Returns the max key (key at root) from min heap
    Pair* DeleteMin();
    void insertKey(Pair* k);
    void swap(Pair* x, Pair* y);
    void deletePairByIndex(int ind);
    void DecreaseKey(int key, int newPri);
};