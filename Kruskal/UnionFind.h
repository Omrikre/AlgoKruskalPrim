//
// Created by Omrik on 5/7/2022.
//

#ifndef UNTITLED_UNIONFIND_H
#define UNTITLED_UNIONFIND_H


#include "../Graph/Edge.h"
#include "../Graph/Graph.h"

//TODO - כיווץ מסלולים

typedef struct {
    int parent;
    int size;
} Element ;


class UnionFind {
private: // members:
    Element* setsArr;
    void sortEdgeList(Edge* edgeLst);


public:
    UnionFind(Graph* graph);

    int find(int vertName);
    void makeSet(int vertName);
    void unionSets(int vert1, int vert2);
};


#endif //UNTITLED_UNIONFIND_H
