#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
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

    //DSU cho Kruskal (Disjoint Set Union)
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int v) {
            return (v == parent[v]) ? v : parent[v] = find(parent[v]);
        }
        bool unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return false;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
    };

public:
    Graph(int n) {
        this->n = n;
        adj.assign(n, vector<int>(n, 0));
        visited.assign(n, false);
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u][v] = w;
        adj[v][u] = w;
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

    void Kruskal() {
        struct Edge { int u, v, w; };
        vector<Edge> edges;

        // lấy danh sách cạnh
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (adj[u][v] != 0) {
                    edges.push_back({u, v, adj[u][v]});
                }
            }
        }

        sort(edges.begin(), edges.end(),
             [](Edge a, Edge b) { return a.w < b.w; });

        DSU dsu(n);
        int mst = 0;

        cout << "Cac canh thuoc MST (Kruskal):\n";

        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) {
                cout << e.u << " - " << e.v << " : " << e.w << endl;
                mst += e.w;
            }
        }

        cout << "Tong trong so MST = " << mst << endl;
    }
    void Prim(int start = 0) {
        vector<bool> used(n, false);
        vector<int> min_w(n, INT_MAX);

        min_w[start] = 0;
        int mst = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!used[j] && (u == -1 || min_w[j] < min_w[u]))
                    u = j;
            }

            used[u] = true;
            mst += min_w[u];

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && !used[v] && adj[u][v] < min_w[v]) {
                    min_w[v] = adj[u][v];
                }
            }
        }

        cout << "Tong trong so MST (Prim) = " << mst << endl;
    }
    void Dijkstra(int start) {
        vector<int> dist(n, INT_MAX);
        vector<bool> used(n, false);
        dist[start] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            for (int j = 0; j < n; j++) {
                if (!used[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            used[u] = true;

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != 0 && dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "Khoang cach tu dinh " << start << ":\n";
        for (int i = 0; i < n; i++) {
            cout << " -> " << i << " : " << dist[i] << endl;
        }
    }
};

#endif

