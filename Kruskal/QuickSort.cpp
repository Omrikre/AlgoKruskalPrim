//
// Created by Omrik on 5/7/2022.
//

#include <iostream>
#include "../Graph/Edge.h"

using namespace std;

int partition(Edge** arr, int start, int end) {
    Edge* pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i]->getWeight() <= pivot->getWeight())
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i]->getWeight() <= pivot->getWeight())
            i++;

        while (arr[j]->getWeight() > pivot->getWeight())
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(Edge** arr, int start, int end) {
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}



