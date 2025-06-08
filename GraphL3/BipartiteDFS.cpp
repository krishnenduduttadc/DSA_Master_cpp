#include <bits/stdc++.h>
using namespace std;

// Depth-First Search to check for bipartiteness
bool dfs(int node, int col, int color[], vector<int> adj[]) {
    color[node] = col;

    for (auto it : adj[node]) {
        if (color[it] == -1) {
            if (!dfs(it, !col, color, adj))
                return false;
        }
        else if (color[it] == col) {
            return false;
        }
    }
    return true;
}

// Main function to check if the graph is bipartite
bool isBipartite(int V, vector<int> adj[]) {
    int color[V];
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0, color, adj))
                return false;
        }
    }
    return true;
}

// Utility function to add an undirected edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 4;
    vector<int> adj[V];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    bool ans = isBipartite(V, adj);
    cout << (ans ? "1" : "0") << endl;

    return 0;
}
