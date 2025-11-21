#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int n;                                  // số đỉnh
    vector<vector<int>> adj;                // ma trận kề
    vector<bool> visited;                   // mảng đánh dấu

    // Hàm DFS đệ quy
    void DFS_Rec(int u) {
        visited[u] = true;
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                DFS_Rec(v);
            }
        }
    }

public:
    Graph(int n) {
        this->n = n;
        adj.assign(n, vector<int>(n, 0));
        visited.assign(n, false);
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }

    void BFS(int start) {
        resetVisited();
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v = 0; v < n; v++) {
                if (adj[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void DFS(int start) {
        resetVisited();
        cout << "DFS: ";
        DFS_Rec(start);
        cout << endl;
    }

    void printMatrix() {
        cout << "Ma tran ke:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif

