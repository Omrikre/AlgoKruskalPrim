//
// Created by Omrik on 5/6/2022.
//

#ifndef UNTITLED_VERT_H
#define UNTITLED_VERT_H

#include "Edge.h"

class Vert {
public:
    void setVertName(int i) { this->vertName = i; }
    void setEdgeList() { this->edgeList = nullptr; }

    int getVertName() const { return vertName; }
    Edge *getEdgeList() const { return edgeList; }

    void addEdgeToList(Edge* newEdge) {
        if (edgeList == nullptr)
            edgeList = newEdge;
        else {
            Edge* tempPointer = edgeList;
            while (tempPointer != nullptr)
                tempPointer = tempPointer->getNextEdge();
            tempPointer = newEdge;
        }
    }

private: // members:
    int vertName;
    Edge* edgeList;
};


#endif //UNTITLED_VERT_H
