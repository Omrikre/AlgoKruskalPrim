//
// Created by Omrik on 5/2/2022.
//

#ifndef UNTITLED_EDGELIST_H
#define UNTITLED_EDGELIST_H

#include "../Edge.h"

struct edgeNode {
    edgeNode(Edge edge) : edge(edge) {}
    Edge edge;
    edgeNode* prev;
    edgeNode* next;
};

class edgeList{
public:
    // ctor
    edgeList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addEdge(Edge newEdge) {
        edgeNode* tmp;
        tmp = new edgeNode(newEdge);
        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;

        }


        size++;
    };
    void removeEdge(int dest) {

        size--;
    };


    int getSize() const { return size; };

    // members:
private:
    edgeNode *head;
    edgeNode *tail;
    int size;
};


#endif //UNTITLED_EDGELIST_H
