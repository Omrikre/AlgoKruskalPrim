//
// Created by Omrik on 5/10/2022.
//

#ifndef UNTITLED_QUICKSORT_H
#define UNTITLED_QUICKSORT_H

#include "../Graph/Edge.h"

class QuickSort {
public:
    void quickSort(Edge** arr, int start, int end);
    int partition(Edge** arr, int start, int end);
    };

#endif //UNTITLED_QUICKSORT_H
