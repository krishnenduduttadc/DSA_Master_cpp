#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    int n, m;
    cin >> n >> m;  // n = number of cities, m = number of roads
    
    vector<vector<int>> adj(n + 1);  // adjacency list for graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // because the graph is undirected
    }

    // Find the number of connected components
    int components = countConnectedComponents(n, adj);

    // Minimum number of roads needed to connect all cities
    int min_new_roads = components - 1;
    cout << min_new_roads << endl;

    return 0;
}



/*
5 6
1 2
2 3
1 3
3 5
2 4
4 5
*/