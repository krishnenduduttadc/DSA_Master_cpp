#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input for testing
    int n = 6; // Number of nodes in the tree
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5}
    };
    
    // This is our adjacency list
    vector<vector<int>> tree(n);
    
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        
        // Adding an edge from u to v
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // Code to print the adjacency list of children of the root node (node 0)
    for (int j : tree[0]) {
        // Print all nodes directly connected to node 0 (children of node 0)
        cout << j << " ";
    }
    cout << "\n";
    
    // Print children of each child of root (leaf nodes)
    for (int j : tree[0]) {
        for (int k : tree[j]) {
            if (k != 0 && find(tree[0].begin(), tree[0].end(), k) == tree[0].end()) {
                // Ensure we don't print parent nodes
                cout << k << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
