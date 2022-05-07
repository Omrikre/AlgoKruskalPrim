//
// Created by Omrik on 5/2/2022.
//

#ifndef UNTITLED_EDGE_H
#define UNTITLED_EDGE_H

class Edge {
private:
    // members:
    int sourceEdge, destEdge, weight;
    Edge* nextEdge;
public:
    // ctor:
    Edge(int source, int dest, int weight) : sourceEdge(sourceEdge), destEdge(dest), weight(weight) {
        nextEdge = nullptr;
    }

    // getters:
    int getSource() const { return sourceEdge; }
    int getDest() const { return destEdge; }
    int getWeight() const { return weight; }
    Edge* getNextEdge() { return nextEdge; }

    // setters:
    void setNextEdge(Edge* next) { this->nextEdge = next; }

};

#endif //UNTITLED_EDGE_H
