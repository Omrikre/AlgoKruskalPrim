
/*TODO
 * print output to file - argv[2]
 * free all data
 * d'tors
 * kruskal
 * union find - array
 * check all input cases
 * documentation
 * check if run in VScode 2019
 * check quickSort - if need graph size -1
 * fix all TODOs
 * fix Prim - works with the old graph (list...)
 * use getDataFromFile
 * check if to add to edgeList (in Graph) both sides of the edge
 * while remove edge, delete it also from the list
 */



#include "Graph/Graph.h"

using namespace std;

int main(int argc, char *argv[]) {
    Graph g;
    int vertsize = 6;
    int edgeSize = 9;
    g.makeEmptyGraph(vertsize);
    g.setEdgeSize(edgeSize);
    g.setVertSize(vertsize);
    g.addEdge(1, 2, 16);
    g.addEdge(1, 3, 13);
    g.addEdge(2, 3, 10);
    g.addEdge(2, 4, 12);
    g.addEdge(4, 3, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4,5,7);
    g.addEdge(5,6, 4);
    g.addEdge(4, 6, 20);

    /*
    6
9
1 2 16
1 3 13
2 3 10
2 4 12
4 3 9
3 5 14
5 4 7
5 6 4
4 6 20
1 3
    */
    // run kruskel
    // run 
}


