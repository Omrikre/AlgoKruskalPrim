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
    ~Graph();
    void getDataFromFile(string fileName,string output);
    void makeEmptyGraph(int vertSize);
    bool isAdjacent(int src, int dest);
    Edge* getAdjList(int vertName);
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);
    void removeEdgeFromTheFile();
    void print();
    int getVertSize() const;
    int getEdgeSize() const;
    int getEdgeListSize() const;
    Edge** getEdgeList() { return this->edgeList; }
    void setVertSize(int size) { vertSize = size; }
    void setEdgeSize(int size) { edgeSize = size; }
    bool checkIfConnected();
    void helper(Vert v,int *arr);

private: // members:
    int vertSize, edgeSize, edgeListSize;
    Vert* vertArr;
    Edge* edgeToRemove;
    Edge** edgeList;

};

#endif