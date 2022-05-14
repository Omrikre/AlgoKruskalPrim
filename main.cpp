
/*
 * Omri Krelman 205800378
 * Nov Israeli 316428358
 * 
 */



#include "Graph/Graph.h"
#include "Prim/Prim.h"
#include "Kruskal/Kruskal.h"

using namespace std;

void printToScreen(int firstKruskal, int secondKruskal, int prim) {
    // prints to console 
    printf("Prim %d\n", prim);
    printf("Kruskal %d\n", firstKruskal);
    printf("Kruskal %d\n", secondKruskal);

}

void printToFile(int firstKruskal, int secondKruskal, int prim, string fileName) {
    // print to file
    ofstream outputFile;
    outputFile.open(fileName);
    outputFile << "Prim " << prim << endl;
    outputFile << "Kruskal " << firstKruskal << endl;
    outputFile << "Kruskal " << secondKruskal << endl;
    outputFile.close();
}

int main(int argc, char *argv[]) {
    Graph g;
    Prim prim;
    int primRes, kruskalRes, kruskalResAfterRemove;
    string outputFikeName = argv[2];
    g.getDataFromFile(argv[1], outputFikeName);
    primRes = prim.primCalc(g);                 // Prim
    kruskalRes = Kruskal(&g);                   // kruskal - first
    g.removeEdgeFromTheFile();                  // remove the edge
    if (!g.checkIfConnected()) {
        cout << endl << "Invalid input" << endl << endl;
        ofstream outputFile;
        outputFile.open(argv[2]);
        outputFile << "invalid input";
        outputFile.close();
        exit(1);
    }
    kruskalResAfterRemove = Kruskal(&g);        // Kruskal - after remove

    printToScreen(kruskalRes, kruskalResAfterRemove, primRes);
    printToFile(kruskalRes, kruskalResAfterRemove, primRes, outputFikeName);



}



