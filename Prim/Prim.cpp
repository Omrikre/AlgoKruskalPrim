//
// Created by Omrik on 4/8/2022.
//

#include "Prim.h"


// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int Prim::primCalc(Graph& g)
{
	cout << "start\n";
	int sum = 0;
	int count = 0;
	size = g.getVertSize();
	arr = new bool(size+1);
	setArr();
	arr[1] = true;
	MinHeap heap(g.getVertSize());
	heap.DeleteMin();
	Edge* n = g.getAdjList(1);
	while (n != nullptr) {
		heap.DecreaseKey(n->getDest(),n->getSource(), n->getWeight());
		n = n->getNextEdge();
	}
	Pair* p = heap.DeleteMin();
	//heap.print();
	count++;
	sum += p->getPriority();
	while (count != g.getVertSize() - 1) {
		if (!arr[p->getDest()]) {
			n = g.getAdjList(p->getDest());
		}
		else {
			int temp = p->getValue();
			n = g.getAdjList(p->getValue());
		}
		while (n != nullptr) {
			if (!arr[(n->getDest())] && !arr[(n->getSource())]) {
				heap.DecreaseKey(n->getDest(), n->getSource(), n->getWeight());
			}
			n = n->getNextEdge();
		}
		arr[p->getValue()] = true;
		arr[p->getDest()] = true;
		p = heap.DeleteMin();
		//heap.print();
		count++;
		sum += p->getPriority();
	}
	return sum;
}



