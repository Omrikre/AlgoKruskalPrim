#include "MinHeap.h"

MinHeap::MinHeap(int arrSize) {
    currSize = 0;
    maxSize = arrSize;
    currSize = arrSize;
    array = new Pair*[arrSize];
    for (int i = 0; i < arrSize; i++) {
        array[i] = new Pair(INT_MAX,i+1);
        array[i]->setIndex(i);
        array[i]->setDest(0);
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
    array[0]->setIndex(0);

    fixHeap(0);

    return res;
}
void MinHeap::fixHeap(int curr) {
    int l = left(curr);
    int r = right(curr);
    int smallest = curr;

    if (!(array[l] == nullptr)) {
        if (l < currSize && array[l]->getPriority()< array[curr]->getPriority())
            smallest = l;
    }
    if (!(array[r] == nullptr)) {
        if (r < currSize && array[r]->getPriority() < array[smallest]->getPriority())
            smallest = r;
    }
    if (smallest != curr) {
        swap(array[curr], array[smallest]);
        fixHeap(smallest);
    }
}
void MinHeap::swap(Pair* x, Pair* y) {
    int i1 = x->getIndex();
    int i2 = y->getIndex();
    array[i1] = y;
    array[i1]->setIndex(i1);
    array[i2] = x;
    array[i2]->setIndex(i2);

   
}
void MinHeap::deletePairByIndex(int ind) {
    swap(array[currSize - 1], array[ind]);
    array[currSize - 1] = nullptr;
    currSize--;

    fixHeap(ind);
}

void MinHeap::DecreaseKey(int key,int key2, int newPri){
    for (int i = 0;i < currSize;i++) {
        if (array[i]->getValue() == key|| array[i]->getValue() == key2) {
            if (array[i]->getPriority() > newPri&& array[i]->getValue() == key) {
                array[i]->setPri(newPri);
                array[i]->setDest(key2);
                fixInsert(i);
                return;
            }
            else if (array[i]->getPriority() > newPri && array[i]->getValue() == key2) {
                array[i]->setPri(newPri);
                array[i]->setDest(key);
                fixInsert(i);
            }
        }
    }
}

void MinHeap::print() {
    for (int i = 0;i < currSize;i++) {
        cout << array[i]->getIndex() << " // " << array[i]->getPriority() << " // " << array[i]->getValue() << " // " << array[i]->getDest()<<"\n";

    }
    cout<< "space\n";
    
}








