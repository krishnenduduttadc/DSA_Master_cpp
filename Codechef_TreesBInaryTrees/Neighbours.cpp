#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 7; // Number of nodes
    int v = 2; // Target node for which we want to find the number of neighbors

    // Define edges directly (hardcoded) as per the example
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 4},
        {2, 5},
        {2, 3},
        {2, 6},
        {4, 7}
    };

    // Adjacency list to store the tree
    vector<vector<int>> adj(N + 1);
    for (auto edge : edges) {
        int u = edge.first, w = edge.second;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    // Get the number of neighbors of node `v`
    int neighbors = adj[v].size();
    cout << neighbors << endl;

    return 0;
}
