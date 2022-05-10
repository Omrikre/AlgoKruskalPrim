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
    void print();
    void getDataFromFile(string fileName);
    int getVertSize() const;
    int getEdgeSize() const;
    Edge** getEdgeList() { return this->edgeList; }
    void setVertSize(int size) { vertSize = size; }
    void setEdgeSize(int size) { edgeSize = size; }
    ~Graph();

private: // members:
    int vertSize, edgeSize, edgeListSize;
    Vert* vertArr;
    Edge* edgeToRemove;
    Edge** edgeList; //TODO - init in ctor check if works good

};

#endif