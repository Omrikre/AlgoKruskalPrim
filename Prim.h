//
// Created by Omrik on 4/8/2022.
//

#ifndef UNTITLED_PRIM_H
#define UNTITLED_PRIM_H

using namespace std;
#include <bits/stdc++.h>


class Prim {

    int minKey(int *key, bool *mstSet);
    void printMST(int parent[], int graph[][]);
    void primMST(int graph[][]);
};


#endif //UNTITLED_PRIM_H

