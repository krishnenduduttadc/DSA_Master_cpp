#include <bits/stdc++.h>
using namespace std;

// Procedure DFS(node, adjList, visited)
void DFS(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited
    // Traverse all the neighbors of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited); // Recursively visit the neighbor
        }
    }
}

// Procedure FindConnectedComponents(n, adjList)
int FindConnectedComponents(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n + 1, false); // Initialize the visited array

    int components = 0; // Initialize components counter
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // If the node has not been visited
            DFS(i, adjList, visited); // Perform DFS from this node
            components++; // Increment the components counter
        }
    }
    return components; // Return the number of connected components
}

int main() {
    // Hardcoded number of nodes and edges
    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Initialize adjacency list
    vector<vector<int>> adjList(n + 1); // 1-based index

    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {1, 3},
        {3, 5},
        {2, 4},
        {4, 5}
    };

    // Adding edges to the adjacency list
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Find and output the number of connected components
    int components = FindConnectedComponents(n, adjList);
    cout << components << endl; // Output the number of connected components

    return 0;
}

/*
Expected Output:
1
*/
