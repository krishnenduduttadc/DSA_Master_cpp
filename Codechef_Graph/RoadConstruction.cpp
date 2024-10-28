#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited
    for (int neighbor : adj[node]) { // Visit all unvisited neighbors
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Function to count connected components in the graph
int countConnectedComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false); // Visited array
    int components = 0; // Counter for connected components

    for (int i = 1; i <= n; i++) { // Iterate through all nodes
        if (!visited[i]) { // If the node has not been visited
            components++; // Increment component count
            dfs(i, adj, visited); // Perform DFS to mark all connected nodes
        }
    }
    return components; // Return the number of connected components
}

int main() {
    // Hardcoded input
    int n = 5; // Number of cities
    int m = 6; // Number of roads

    // Hardcoded edges (roads)
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {1, 3},
        {3, 5},
        {2, 4},
        {4, 5}
    };

    vector<vector<int>> adj(n + 1); // Adjacency list for the graph
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v); // Add road from city u to v
        adj[v].push_back(u); // Add road from city v to u (undirected)
    }

    // Find the number of connected components
    int components = countConnectedComponents(n, adj);

    // Minimum number of roads needed to connect all cities
    int min_new_roads = components - 1;
    cout << "Minimum new roads needed: " << min_new_roads << endl;

    return 0;
}

/*
Expected output for the given hardcoded example:
Minimum new roads needed: 0
*/
