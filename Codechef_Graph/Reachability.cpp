#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1; // Maximum number of nodes
vector<int> adj[N]; // Adjacency list
vector<bool> vis(N, 0); // Visited array

// Function to perform DFS
void dfs(int v) {
    if(vis[v]) {
        return; // Node already visited
    }
    vis[v] = true; // Mark current node as visited

    for(auto u: adj[v]) {
        dfs(u); // Recursively visit all adjacent nodes
    }
}

int main() {
    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {1, 3},
        {4, 3},
        {3, 2},
        {2, 4},
        {5, 4},
        {3, 1}
    };

    // Constructing the adjacency list from hardcoded edges
    for (auto edge : edges) {
        int a = edge.first;
        int b = edge.second;
        adj[a].push_back(b); // Directed edge
    }

    dfs(1); // Start DFS from source: 1

    cout << "Nodes reachable from node 1: ";
    for(int i = 1; i <= n; i++) {
        if(vis[i]) { // A node is reachable if it is marked visited
            cout << i << " "; // Print reachable nodes
        }
    }
    cout << endl;

    return 0;
}

/*
Expected output for the given hardcoded example:
Nodes reachable from node 1: 1 2 3 
*/
