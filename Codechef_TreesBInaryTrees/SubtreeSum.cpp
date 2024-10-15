#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<long long>& subtreeSum) {
    // Initialize the subtree sum of this node with its own value (node number)
    subtreeSum[node] = node;

    // Visit all neighbors (children)
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {  // Avoid going back to the parent node
            dfs(neighbor, node, adj, subtreeSum);  // Recursively calculate subtree sum for the child
            subtreeSum[node] += subtreeSum[neighbor];  // Add the child's subtree sum to this node's sum
        }
    }
}

int main() {
    int N;
    cin >> N; // Read the number of nodes

    vector<vector<int>> adj(N + 1); // Adjacency list (1-based indexing)

    // Read the edges
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v; // Read each edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> subtreeSum(N + 1, 0); // To store the subtree sum of each node

    // Perform DFS starting from node 1 (root node), with parent as -1 (since root has no parent)
    dfs(1, -1, adj, subtreeSum);

    // Output the subtree sums for nodes from 1 to N
    for (int i = 1; i <= N; ++i) {
        cout << subtreeSum[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
7 
1 2
1 4
2 5
2 3
2 6
4 7

*/