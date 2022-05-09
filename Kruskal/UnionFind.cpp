//
// Created by Omrik on 5/7/2022.
//

#include "UnionFind.h"

UnionFind::UnionFind(Graph* graph) {
    int vertSize = graph->getVertSize();
    auto arr = new Element[vertSize];
    this->setsArr = arr;

    for (int i = 1; i <= vertSize; ++i) {
        makeSet(i);
    }
}

void UnionFind::makeSet(int vertName) {
    this->setsArr[vertName-1].parent = vertName;     // set parent
    this->setsArr[vertName].size = 1;                // set size
}

int UnionFind::find(int vertName) {
    if(setsArr[vertName-1].parent == vertName-1)
        return vertName;
    else // shrink paths
        return (setsArr[vertName-1].parent = find(setsArr[vertName-1].parent));
}

void UnionFind::unionSets(int vert1, int vert2) {
    // union by size
    if (setsArr[vert1-1].size > setsArr[vert2-1].size) {
        setsArr[vert2-1].parent = vert1;
        setsArr[vert1-1].size += setsArr[vert2-1].size;
    }
    else {
        setsArr[vert1-1].parent = vert2;
        setsArr[vert2-1].size += setsArr[vert1-1].size;
    }
}

