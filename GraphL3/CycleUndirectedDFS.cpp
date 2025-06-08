#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, node, vis, adj))
                return true;
        }
        else if (it != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}

int main() {
    // V = 4, E = 2
    vector<int> adj[4] = {
        {},       // 0
        {2},      // 1
        {1, 3},   // 2
        {2}       // 3
    };

    bool ans = isCycle(4, adj);
    cout << (ans ? "1\n" : "0\n");

    return 0;
}
