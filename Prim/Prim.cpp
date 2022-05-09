//
// Created by Omrik on 4/8/2022.
//

#include "Prim.h"
#include "../Graph/Graph.h"


// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST

int Prim::primCalc(Graph g)
{
	int sum = 0;
	int count = 0;
	MinHeap heap(g.getSize());
	int dest = 0;
	int weight = 0;
	Graph::List::Node* n = g.getAdjList(1).getHead();
	while (n != nullptr) {
		heap.DecreaseKey(n->getDest(), n->getWeight());
		n->getNext();
	}
	Pair* p = heap.DeleteMin();
	count++;
	sum += p->getPriority();
	while (count != g.getSize() - 1) {
		Graph::List::Node* n = g.getAdjList(p->getValue()).getHead();
		while (n != nullptr) {
			heap.DecreaseKey(n->getDest(), n->getWeight());
			n->getNext();
		}
		Pair* p = heap.DeleteMin();
		count++;
		sum += p->getPriority();
	}
	return sum;
}