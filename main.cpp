#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[]) {
    Graph graph;
    graph.getDataFromFile(argv[1]);

    // run kroskel
    // run


        /* Let us create above shown weighted
        and undirected graph */
        int V = 9, E = 14;
        Graph g(V, E);

        // making above shown graph
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);

        cout << "Edges of MST are \n";
        int mst_wt = g.kruskalMST();

        cout << "\nWeight of MST is " << mst_wt;

        return 0;

}


