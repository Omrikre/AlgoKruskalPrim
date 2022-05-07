#include "MinHeap.h"

MinHeap::MinHeap(int arrSize) {
    currSize = 0;
    maxSize = arrSize;
    currSize = arrSize;
    array = new Pair*[arrSize];
    for (int i = 1; i <= arrSize-1; i++) {
        array[i]->setValue(i+1);
        array[i]->setPri(INT_MAX);
        array[i]->setIndex(i);
    }
}
void MinHeap::insertKey(Pair* k) {
  

    // insert new key
    currSize++;
    array[currSize - 1] = k;

    // Fix the min heap property if it is violated
    fixInsert(currSize - 1);
}
void MinHeap::fixInsert(int index) {
    while (index != 0 && array[parent(index)]->getPriority() > array[index]->getPriority()) {
        swap(array[index], array[parent(index)]);
        index = parent(index);
    }
}
Pair* MinHeap::DeleteMin() {
    
    Pair* res = GetMin();
    if (res == nullptr) {
        return res;
    }
    if (currSize == 1) {
        currSize--;
        array[0] = nullptr;
        return res;
    }

    swap(array[currSize - 1], array[0]);
    array[currSize - 1] = nullptr;
    currSize--;

    fixHeap(0);

    return res;
}
void MinHeap::fixHeap(int curr) {
    int l = left(curr);
    int r = right(curr);
    int smallest = curr;

    if (!(array[l] == nullptr)) {
        if (l < currSize && array[l]->getPriority()> array[curr]->getPriority())
            smallest = l;
    }
    if (!(array[r] == nullptr)) {
        if (r < currSize && array[r]->getPriority() > array[smallest]->getPriority())
            smallest = r;
    }
    if (smallest != curr) {
        swap(array[curr], array[smallest]);
        fixHeap(smallest);
    }
}
void MinHeap::swap(Pair* x, Pair* y) {
    
    array[x->getIndex()] = y;
    array[y->getIndex()] = x;
   
}
void MinHeap::deletePairByIndex(int ind) {
    swap(array[currSize - 1], array[ind]);
    array[currSize - 1] = nullptr;
    currSize--;

    fixHeap(ind);
}

void MinHeap::DecreaseKey(int key, int newPri){
    for (int i = i;i < currSize;i++) {
        if (array[i]->getValue() == key) {
            if (array[i]->getPriority() > newPri) {
                array[i]->setPri(newPri);
                fixInsert(i);
            }
            return;
        }
    }
}








