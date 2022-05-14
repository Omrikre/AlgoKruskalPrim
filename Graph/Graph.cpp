//
// Created by Omrik on 4/5/2022.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;


Graph::Graph() {
    vertSize = 0;
    edgeSize = 0;
    edgeListSize = 0;
    vertArr = nullptr; 
    edgeToRemove = nullptr;
    edgeList = nullptr;
}

Graph::~Graph() {
    Edge* currEdge;
    for (int i = 0; i < edgeListSize; i++) {
        currEdge = edgeList[i];
        if (currEdge != nullptr)
            free(currEdge);
    }
}

void Graph::getDataFromFile(string fileName,string output) {
    ifstream  dataFile;
    int vertNum, edgeNum;
    int edgeWeight=0, fromVert=0, toVert=0;
    string tempLine;
    string line;
    bool done1 = false, done2 = false, done3 = false;

    dataFile.open(fileName);
    dataFile >> vertNum;
    dataFile >> edgeNum;

    if ((vertNum < 1 || edgeNum < 1)) {
        cout << endl << "Invalid input" << endl << endl;
        exit(1);
    }

    // set vertices and edges sizes
    this->vertSize = (int)vertNum;
    this->edgeSize = (int)edgeNum;
    getline(dataFile, line);

    makeEmptyGraph(vertSize);


    this->edgeListSize = 0;
    
    for (int i = 0; i < (int)edgeNum; ++i) {

        getline(dataFile, line);
        

        for (int j = 0; j < line.length();j++) {
            if (done1 && done2 && done3) {
                cout << "invalid input";
                ofstream outputFile;
                outputFile.open(output);
                outputFile << "invalid input";
                outputFile.close();
                exit(1);
            }
            //take first num
            else if (!done1) {
                if (line[j] == ' ') {
                    done1 = true;
                }
                else {
                    fromVert *= 10;
                    fromVert += (line[j] - 48);
                }
            }
            //take second num
            else if (done1 && !done2) {
                if (line[j] ==' ') {
                    done2 = true;
                }
                else {
                    toVert *= 10;
                    toVert += (line[j] - 48);
                }
            }
            else {
                if (line[j] == ' ') {
                    done3 = true;
                }
                else {
                    edgeWeight *= 10;
                    edgeWeight += (line[j] - 48);
                }
            }
        }
        if ((done1 && done2 && !done3 && edgeWeight == 0)|| (done1 && !done2 && !done3 && edgeWeight == 0)) {
            cout << "invalid input";
            ofstream outputFile;
            outputFile.open(output);
            outputFile << "invalid input";
            outputFile.close();
            exit(1);
            //
        }
        done1 = false;
        done2 = false;
        done3 = false;
        if (fromVert<0 || fromVert>vertSize || toVert<0 || toVert>vertSize) {
            cout << endl << "Invalid input" << endl << endl;
            ofstream outputFile;
            outputFile.open(output);
            outputFile << "invalid input";
            outputFile.close();
            exit(1);
        } 
        
        addEdge(fromVert, toVert, edgeWeight);
        addEdge(toVert, fromVert, edgeWeight);
        fromVert = 0;
        toVert = 0;
        edgeWeight = 0;
    }
    getline(dataFile, line);
    for (int j = 0; j < line.length();j++) {
        if (done1 && done2) {
            cout << "invalid input";
            ofstream outputFile;
            outputFile.open(output);
            outputFile << "invalid input";
            outputFile.close();
            exit(1);
        }
        //take first num
        else if (!done1) {
            if (line[j] == ' ') {
                done1 = true;
            }
            else {
                fromVert *= 10;
                fromVert += (line[j] - 48);
            }
        }
        //take second num
        else if (done1 && !done2) {
            if (line[j] == ' ') {
                done2 = true;
            }
            else {
                toVert *= 10;
                toVert += (line[j] - 48);
            }
        }
    }
    dataFile >> fromVert;
    dataFile >> toVert;
    this->edgeToRemove = new Edge(fromVert, toVert, 0);
    if (!checkIfConnected()) {
        cout << endl << "Invalid input" << endl << endl;
        ofstream outputFile;
        outputFile.open(output);
        outputFile << "invalid input";
        outputFile.close();
        exit(1);
    }
    dataFile.close();
}

bool Graph::checkIfConnected() {
    int temp;
    int* arr = new int(vertSize);
    for (int i = 0;i < vertSize;i++) {
        arr[i] = 1;
        temp = arr[i];
    }
    helper(vertArr[0], arr);
    for (int i = 0;i < vertSize;i++) {
        if (arr[i] == 1) {
            return false;
        }
    }
    return true;
}

void Graph::helper(Vert v,int *arr) {
    int t;
    int temp = v.getVertName();
    arr[temp - 1] = 2;
    Edge* e = v.getEdgeList();
    while (e != nullptr) {
        t = e->getDest();
        if (arr[t-1] != 2) {
            helper(vertArr[t-1], arr);
        }
        e = e->getNextEdge();
    }
}

void Graph::makeEmptyGraph(int vertSize) {
    this->vertArr = new Vert[vertSize];
    this->edgeList = new Edge*[edgeSize*2];
    for (int i = 1; i <= vertSize; ++i) {
        this->vertArr[i - 1] = Vert();
        this->vertArr[i-1].setVertName(i);
        this->vertArr[i-1].setEdgeList();
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge* newEdge = new Edge(src, dest, weight);
    this->vertArr[src - 1].addEdgeToList(newEdge);
    this->edgeList[edgeListSize] = newEdge;
    this->edgeListSize += 1;
}

Edge* Graph::getAdjList(int vertName) {
    if (vertName > vertSize || vertName < 1) {
        cout << endl << "Invalid input" << endl << endl;
        return nullptr;
    }
    return vertArr[vertName - 1].getEdgeList();
}

void Graph::removeEdge(int src, int dest) {
    if (src > vertSize || src<1 || dest>vertSize || dest < 1) {
        cout << endl << "Invalid input" << endl << endl;
        return;
    }
    
    for (int i = 0; i < edgeListSize; i++) {
        if (edgeList[i]->getDest() == dest && edgeList[i]->getSource() == src) {
            for (int j = i; j < edgeListSize - 1; j++) {
                edgeList[j] = edgeList[j+1];            }
            i--;
            this->edgeListSize -= 1;
        }
            
        else if (edgeList[i]->getDest() == src && edgeList[i]->getSource() == dest) {
            for (int j = i; j < edgeListSize - 1; j++) {
                edgeList[j] = edgeList[j+1];
            }
            i--;
            this->edgeListSize -= 1;
        }
    }

    Edge* currEdge = vertArr[src - 1].getEdgeList();
    Edge* prevEdge = nullptr;
    bool edgeFound = false;

    while (!edgeFound) {
        if (currEdge != nullptr) {
            if (currEdge->getDest() == dest)
                edgeFound = true;
            else {
                prevEdge = currEdge;
                currEdge = currEdge->getNextEdge();
            }
        }
        else {
            cout << "Edge to remove doesnt exist" << endl;
            return;
        }
    }
    if (prevEdge == nullptr) {
        vertArr[src - 1].setEdgeList(currEdge->getNextEdge());
        free(currEdge);
    }
    else {
        prevEdge->setNextEdge(currEdge->getNextEdge());
        free(currEdge);
    }

    // delete other side

    currEdge = vertArr[dest - 1].getEdgeList();
    prevEdge = nullptr;
    edgeFound = false;

    while (!edgeFound) {
        if (currEdge != nullptr) {
            if (currEdge->getDest() == src)
                edgeFound = true;
            else {
                prevEdge = currEdge;
                currEdge = currEdge->getNextEdge();
            }
        }
        else {
            cout << "Edge to remove doesnt exist" << endl;
            return;
        }
    }
    if (prevEdge == nullptr) {
        vertArr[dest - 1].setEdgeList(currEdge->getNextEdge());
        free(currEdge);
    }
    else {
        prevEdge->setNextEdge(currEdge->getNextEdge());
        free(currEdge);
    }

    this->edgeSize -= 1;
}

void Graph::removeEdgeFromTheFile() {
    removeEdge(this->edgeToRemove->getSource(), this->edgeToRemove->getDest());
}

bool Graph::isAdjacent(int src, int dest) {
    Edge* currEdge = vertArr[src - 1].getEdgeList();

    while (currEdge != nullptr) {
        if (currEdge->getDest() == dest)
            return true;
        else
            currEdge = currEdge->getNextEdge();
    }
    return false;
}

int Graph::getVertSize() const { return vertSize; }

int Graph::getEdgeSize() const { return edgeSize; }

int Graph::getEdgeListSize() const{ return edgeListSize; }

void Graph::print() {
    cout << "Num of edges: " << this->edgeSize << endl;
    cout << "Num of edges lise: " << this->edgeListSize << endl << endl;

    cout << endl << "Edges:" << endl;
    for (int i = 0; i < this->edgeListSize; i++) {
        cout << i+1 << ".  " << "from - " << this->edgeList[i]->getSource() << " to - " << this->edgeList[i]->getDest() << " weight - " << this->edgeList[i]->getWeight() << endl;
    }
    cout << endl << "Edge to remove:" << endl;
    cout << "from - " << this->edgeToRemove->getSource() << " to - " << this->edgeToRemove->getDest() << endl;

/*
    Edge* n = nullptr;
    for (int i = 1;i <= vertSize;i++) {
        n = vertArr[i].getEdgeList();
        while (n != nullptr) {
            cout << "edge checked:" << n->getDest() << " // " << n->getSource() << "\n";
            n = n->getNextEdge();
        }
    }*/
}



