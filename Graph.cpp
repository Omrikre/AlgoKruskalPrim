//
// Created by Omrik on 4/5/2022.
//

#include "Graph.h"

void Graph::addEdge(int src, int dest, int weight) {
    arr[src].addEdge(dest,weight);
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
}
Graph::List Graph::getAdjList(int src) {
    return arr[src];
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