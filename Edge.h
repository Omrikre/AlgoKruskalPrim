//
// Created by Omrik on 5/2/2022.
//

#ifndef UNTITLED_EDGE_H
#define UNTITLED_EDGE_H

class Edge {
private:
    // members:
    int source, dest, weight;
public:
    // ctor:
    Edge(int source, int dest, int weight) : source(source), dest(dest), weight(weight) {}

    // getters:
    int getSource() const { return source; }
    int getDest() const { return dest; }
    int getWeight() const { return weight; }

};

#endif //UNTITLED_EDGE_H
