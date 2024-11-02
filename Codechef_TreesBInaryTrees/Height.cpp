#include <bits/stdc++.h>

using namespace std;

// DFS function to calculate the height of the tree
int dfs(int s, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[s] = true;
    int maxHeight = 0; // Maximum height from the current node

    for (int it : adj[s]) {
        if (!visited[it]) { // If the neighbor has not been visited
            int childHeight = dfs(it, adj, visited); // Recur for the child
            maxHeight = max(maxHeight, childHeight); // Update maxHeight
        }
    }
    return maxHeight + 1; // Add one for the current node
}

int main() {
    int n = 8; // Hardcoded number of vertices
    vector<vector<int>> adj(n + 1); // Adjacency list to store graph

    // Hardcoded edges
    int edges[][2] = {
        {1, 2},
        {1, 3},
        {3, 4},
        {3, 5},
        {3, 6},
        {2, 7},
        {2, 8}
    };

    // Add edges to the adjacency list
    for (int i = 0; i < 7; i++) { // There are 7 edges
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // Add edge from u to v
        adj[v].push_back(u); // Add edge from v to u
    }

    vector<bool> visited(n + 1, false); // Initialize visited array
    int height = dfs(1, adj, visited) - 1; // Subtract 1 because the root node itself doesn't add to height
    cout << height << endl; // Output the height of the tree

    return 0;
}

/*
Expected Output:
3
*/
