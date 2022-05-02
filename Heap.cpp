#include "Heap.h"

Heap::~Heap(){
	for (int i = 0;i < maxSize;i++) {
		delete array[i];
	}
	delete[]array;
}
