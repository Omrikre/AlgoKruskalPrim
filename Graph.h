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
    List getAdjList(int src);

    //inner class List
    class List{
    public:
        List(){
            head= nullptr;
            tail= nullptr;
        }
        void addEdge(int dest,int weight);
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
       //end of inner class node
    private:
        Node *head;
        Node *tail;

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

};


#endif //UNTITLED_GRAPH_H
