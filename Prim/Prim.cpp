//
// Created by Omrik on 4/8/2022.
//

#include "Prim.h"
#include "MinHeap.h"


// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST

int Prim::primCalc(Graph g)
{
	int sum = 0;
	int count = 0;
	MinHeap heap(g.getVertSize());
	int dest = 0;
	int weight = 0;
	Edge* n = g.getAdjList(1);
	while (n != nullptr) {
		heap.DecreaseKey(n->getDest(), n->getWeight());
		n = n->getNextEdge();
	}
	Pair* p = heap.DeleteMin();
	count++;
	sum += p->getPriority();
	while (count != g.getVertSize() - 1) {
		Edge* n = g.getAdjList(1);
		while (n != nullptr) {
			heap.DecreaseKey(n->getDest(), n->getWeight());
			n = n->getNextEdge();
		}
		Pair* p = heap.DeleteMin();
		count++;
		sum += p->getPriority();
	}
	return sum;
}