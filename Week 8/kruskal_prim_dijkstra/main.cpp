#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 3, 4);
    g.addEdge(3, 4, 3);
    g.addEdge(2, 4, 1);

    g.printMatrix();

    g.Kruskal();
    g.Prim(0);
    g.Dijkstra(0);

    return 0;
}
