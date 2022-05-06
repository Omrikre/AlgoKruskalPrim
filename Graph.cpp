//
// Created by Omrik on 4/5/2022.
//

#include "Graph.h"


int Graph::getVertSize() const { return vertSize; }
int Graph::getEdgeSize() const { return edgeSize; }
Edge *Graph::getEdges() const { return edges; }

Graph::Graph(int vertSize, int edgeSize) {
    this->edgeSize = edgeSize;
    this->vertSize = vertSize;
    this->edges =
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge *newEdge = new Edge(src, dest, weight);
    E

}










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
void Graph::getDataFromFile(string fileName) {
    ifstream  dataFile;
    float vertNum, edgeNum;
    int edgeWeight, fromVert, toVert;
    string tempLine;

    dataFile.open("C:\\Users\\Omrik\\Desktop\\text.txt");
    dataFile >> vertNum;
    dataFile >> edgeNum;

    if(vertNum < 1 || edgeNum < 1) {
        cout << endl << "Invalid input" << endl << endl;
        exit(1);
    }

    this->size = (int)vertNum;
    this->edgeSize = (int)edgeNum;

    setArray();

    //  print check
    cout << "Num of verts: " << vertNum << endl;
    cout << "Num of edges: " << edgeNum << endl << endl;
    cout << "Edges:" << endl;

    for (int i = 0; i < (int)edgeNum; ++i) {
        dataFile >> tempLine;
        sscanf(tempLine.c_str(), "%d %d %d", &fromVert, &toVert, &edgeWeight);
        if(edgeWeight<0) {
            cout << endl << "Invalid input" << endl << endl;
            exit(1);
        }
        cout << "from - " << fromVert << " to - " << toVert << " weight - " << edgeWeight << endl;
    }
    dataFile.close();
}

void Graph::checkIfVertInGraph() {

}

void Graph::setArray() {
    this->arr = new List[this->size];
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

 /*
  * void Graph::addEdge(int src, int dest, int weight) {
    arr[src].addEdge(dest,weight);
    arr[dest].addEdge(src, weight);
}
  */




