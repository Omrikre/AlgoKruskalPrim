//
// Created by Nov on 4/5/2022.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;


/*
 * (n(MakeEmptyGraph – יצירת גרף ריק מקשתות עם n קדקודים.
(v,u(IsAdjacent – מחזיר כן אם הקשת (v,u (שייכת לגרף, ואחרת לא.
(u(GetAdjList – החזרת רשימה מקושרת של השכנים של קדקוד u.
.c משקל בעלת) u,v) קשת הוספת – AddEdge(u,v,c)
.מהגרף) u,v) הקשת הסרת – RemoveEdge(u,v)
 */


class Graph {
public:
    Graph() {}
    void addEdge(int src,int dest,int weight);
    
    int getSize() { return size; }
    void removeEdge(int src, int dest);

    //inner class List
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
    //end of inner class List
private:
    int size, edgeSize;
    List* arr;

    void addEdge(int src, int dest, int weight);
    void checkIfVertInGraph();
    void setArray();
public:
    void getDataFromFile(string fileName);
    List getAdjList(int src);
    
};


#endif //UNTITLED_GRAPH_H
