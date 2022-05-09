//
// Created by Omrik on 4/5/2022.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
Graph::Graph() {}

void Graph::getDataFromFile(string fileName) {
    ifstream  dataFile;
    float vertNum, edgeNum;
    int edgeWeight, fromVert, toVert;
    string tempLine;

    //TODO - change default location to the "file name"

    dataFile.open("C:\\Users\\Omrik\\Desktop\\text.txt");
    dataFile >> vertNum;
    dataFile >> edgeNum;

    if ((vertNum < 1 || edgeNum < 1)) {
        cout << endl << "Invalid input" << endl << endl;
        exit(1);
    }

    // set vertices and edges sizes
    this->vertSize = (int)vertNum;
    this->edgeSize = (int)edgeNum;

    makeEmptyGraph(vertSize);

    //TODO remove the prints
    // print check
    cout << "Num of verts: " << vertNum << endl;
    cout << "Num of edges: " << edgeNum << endl << endl;
    cout << "Edges:" << endl;

    for (int i = 0; i < (int)edgeNum; ++i) {
        //dataFile >> tempLine;
        sscanf(tempLine.c_str(), "%d %d %d", &fromVert, &toVert, &edgeWeight);
        if (fromVert<0 || fromVert>vertSize || toVert<0 || toVert>vertSize) {
            cout << endl << "Invalid input" << endl << endl;
            exit(1);
        }
        //TODO remove
        cout << "from - " << fromVert << " to - " << toVert << " weight - " << edgeWeight << endl;

        addEdge(fromVert, toVert, edgeWeight);
        addEdge(toVert, fromVert, edgeWeight);
    }
    //dataFile >> tempLine;
    sscanf(tempLine.c_str(), "%d %d", &fromVert, &toVert);
    this->edgeToRemove = new Edge(fromVert, toVert, 0);
    dataFile.close();
}

void Graph::makeEmptyGraph(int vertSize) {
    this->vertArr = new Vert[vertSize];
    for (int i = 1; i <= vertSize; ++i) {
        this->vertArr[i - 1] = Vert();
        this->vertArr[i-1].setVertName(i);
        this->vertArr[i-1].setEdgeList();
    }
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge* newEdge = new Edge(src, dest, weight);
    this->vertArr[src - 1].addEdgeToList(newEdge);
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

    Edge* currEdge = vertArr[src - 1].getEdgeList();
    Edge* prevEdge = nullptr;
    bool edgeFound = false;

    while (!edgeFound) {
        if (currEdge != nullptr) {
            if (currEdge->getDest() == dest)
                edgeFound = true;
            else
                prevEdge = currEdge;
            currEdge = currEdge->getNextEdge();
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
            else
                prevEdge = currEdge;
            currEdge = currEdge->getNextEdge();
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

Graph::~Graph(){
    for (int i = 0;i < vertSize;i++) {
        Edge* n = vertArr[1].getEdgeList();
        n = n->getNextEdge();
        Edge* temp = vertArr[1].getEdgeList();
        while (n != nullptr) {
            delete temp;
            Edge* temp = n;
            n = n->getNextEdge();
        }
        delete temp;
    }
}

void Graph::print() {
    Edge* n = nullptr;
    for (int i = 1;i <= vertSize;i++) {
        n = vertArr[i].getEdgeList();
        while (n != nullptr) {
            cout << "edge checked:" << n->getDest() << " // " << n->getSource() << "\n";
            n = n->getNextEdge();
        }
    }
}











/*
int isCycle() {
    // Allocate memory for creating V subsets
    int* parent = new int[graph->V * sizeof(int)];
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);
    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}
void Graph::List::addEdge(int dest, int weight) {
    Node *n = new Node(dest,weight);
    if (head == nullptr) {
        head=n;
        tail=n;
    }
    else{
        tail->setNext(n);
    }
    size++;
}
Graph::List Graph::getAdjList(int src) {
    return arr[src];
}
void Graph::removeEdge(int src, int dest) {
    arr[src].removeEdge(dest);
    arr[dest].removeEdge(src);
}
void Graph::List::removeEdge(int dest){
    Node* n =head;
    Node* pre = nullptr;
    while (n != nullptr) {
        if (n->getDest()== dest) {
            if (pre==nullptr){
                head = n->getNext();
            }
            if (n == tail) {
                tail = pre;
            }
            else {
                pre->setNext(n->getNext());
            }
        }
        pre = n;
        n = n->getNext();
    }
    size--;
}
void Graph::removeEdge(int src, int dest) {
    arr[src].removeEdge(dest);
    arr[dest].removeEdge(src);
}
void Graph::List::removeEdge(int dest){
    Node* n =head;
    Node* pre = nullptr;
    while (n != nullptr) {
        if (n->getDest()== dest) {
            if (pre==nullptr){
                head = n->getNext();
            }
            if (n == tail) {
                tail = pre;
            }
            else {
                pre->setNext(n->getNext());
            }
        }
        pre = n;
        n = n->getNext();
    }
}
int Graph::partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void Graph::quickSort(int arr[], int start, int end) {
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end);
    // Sorting the left part
    quickSort(arr, start, p - 1);
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
*/