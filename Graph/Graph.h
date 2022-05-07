//
// Created by Nov on 4/5/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <fstream>
#include "Vert.h"

using namespace std;

class Graph {
public: // methods:
    Graph();
    void makeEmptyGraph(int vertSize);
    bool isAdjacent(int src, int dest);
    Edge* getAdjList(int vertName);
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);

    void getDataFromFile(string fileName);
    int getVertSize() const;
    int getEdgeSize() const;
    void setVertSize(int size) { vertSize = size; }
    void setEdgeSize(int size) { edgeSize = size; }



private:
    void checkIfVertInGraph();
    void setArray();
    bool isCycle(Graph* graph);

private: // members:
    int vertSize, edgeSize;
    Vert* vertArr;
    Edge* edgeToRemove;

};

#endif