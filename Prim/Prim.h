//
// Created by Omrik on 4/8/2022.
//

#ifndef UNTITLED_PRIM_H
#define UNTITLED_PRIM_H

#include "MinHeap.h"
#include "../Graph/Graph.h"

using namespace std;



class Prim {
public:
	bool* arr;
	int size;
	int primCalc(Graph& g);
	void setArr() {
		for (int i = 0; i < size; i++) {
			arr[i] = false;
		}
	};
};

#endif UNTITLED_PRIM_H

