//
// Created by Omrik on 4/8/2022.
//


#include "../Graph/Graph.h"
#include "UnionFind.h"
#include "QuickSort.cpp"

int Kruskal(Graph* graph) {
    int res = 0;
    UnionFind uFind = UnionFind(graph);
    Edge* edgeLsrPtr = graph->getEdgeList();
    int edgeLstSize = graph->getEdgeSize();
    quickSort(edgeLsrPtr, 0, graph->getVertSize()-1);

    int parentSour, parentDest;
    for (int i = 0; i < edgeLstSize; ++i) {
        parentSour = uFind.find(edgeLsrPtr[i].getSource());
        parentDest = uFind.find(edgeLsrPtr[i].getDest());
        if(parentSour != parentDest) {
            res += edgeLsrPtr[i].getWeight();
            uFind.unionSets(parentSour, parentDest);
        }
    }
    return res;
}



/*
int Kruskal::calcMin() {

}

int Kruskal::kruskalMST()
{
    int mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
    */
