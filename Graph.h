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
    void getDataFromFile(string fileName);
    void makeEmptyGraph(int vertSize);
    void addEdge(int src, int dest, int weight);
    Edge* getAdjList(int vertName);



    void removeEdge(int src, int dest);
    bool isCycle(Graph *graph);

private:
    void checkIfVertInGraph();
    void setArray();

private: // members:
    int vertSize, edgeSize;
    Vert* vertArr;
    Edge* edgeToRemove;


};


/*
    List* arr;

    // inner class List:
public:
    class List{
    public:
        List(){
            head= nullptr;
            tail= nullptr;
            size = 0;
        }
        void addEdge(int dest,int weight);
        void removeEdge(int dest);
        int getSize() { return size; };
        //inner class Node
        class Node{
        private:
            int dest;
            int weight;
            Node *next;
        public:
            Node(int d,int w):dest(d),weight(w),next(nullptr){}
            int getDest(){return dest;}
            void setDest(int d){dest=d;}
            Node* getNext(){return next;}
            void setNext(Node* n){next=n;}
            int getWeight(){return weight;}
            void setWeight(int w){weight=w;}
            //need distructor?
        };
        Node* getHead() {
            return head;
        }
       //end of inner class node
    private:
        Node *head;
        Node *tail;
        int size;
    };






public:
    void getDataFromFile(string fileName);
    List getAdjList(int src);
    
};


#endif //UNTITLED_GRAPH_H
*/