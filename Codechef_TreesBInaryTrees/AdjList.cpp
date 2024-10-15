#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // This is our adjacency list
    vector<vector<int>> tree(n);
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        
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

/*
6
0 1
0 2
1 3
1 4
2 5
*/