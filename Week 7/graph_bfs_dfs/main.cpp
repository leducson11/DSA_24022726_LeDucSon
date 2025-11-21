#include "Graph.h"

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.printMatrix();

    g.BFS(0);
    g.DFS(0);

    return 0;
}
