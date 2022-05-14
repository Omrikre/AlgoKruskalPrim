//
// Created by Omrik on 4/8/2022.
//


#include "../Graph/Graph.h"
#include "UnionFind.h"

int compareEdgeByWeight(const void* a, const void* b) {
    int res = ((*(Edge**)a)->getWeight() - (*(Edge**)b)->getWeight());
    return res;
}

int Kruskal(Graph* graph) {
    int res = 0;
    UnionFind uFind = UnionFind(graph);
    Edge** edgeLsrPtr = graph->getEdgeList();
    int edgeLstSize = graph->getEdgeSize();
    qsort(edgeLsrPtr, graph->getEdgeListSize(), sizeof(Edge*), compareEdgeByWeight);

    int parentSrc, parentDest, vertAdded = 0;
    for (int i = 0; vertAdded < graph->getVertSize() -1 ; ++i) {
        parentSrc = uFind.find(edgeLsrPtr[i]->getSource());
        parentDest = uFind.find(edgeLsrPtr[i]->getDest());
        if(parentSrc != parentDest) {
            res += edgeLsrPtr[i]->getWeight();
            uFind.unionSets(parentSrc, parentDest);
            vertAdded++;
        }        
    }
    return res;
}


