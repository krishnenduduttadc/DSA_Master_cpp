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
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1); // Initialize adjacency list

    // Read edges and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Find and output the number of connected components
    int components = FindConnectedComponents(n, adjList);
    cout << components << endl;

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