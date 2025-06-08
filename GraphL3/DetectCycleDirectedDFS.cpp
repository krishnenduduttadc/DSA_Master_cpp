#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 11;
    vector<int> adj[11] = {
        {},     // 0
        {2},    // 1
        {3},    // 2
        {4, 7}, // 3
        {5},    // 4
        {6},    // 5
        {},     // 6
        {5},    // 7
        {9},    // 8
        {10},   // 9
        {8}     // 10
    };

    bool ans = isCyclic(V, adj);

    cout << (ans ? "True" : "False") << "\n";

    return 0;
}
