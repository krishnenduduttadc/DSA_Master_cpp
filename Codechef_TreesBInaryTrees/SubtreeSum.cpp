#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and calculate subtree sums
void dfs(int node, int parent, vector<vector<int>>& adj, vector<long long>& subtreeSum) {
    // Initialize the subtree sum of this node with its own value (node number)
    subtreeSum[node] = node;

    // Visit all neighbors (children)
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (neighbor != parent) {  // Avoid going back to the parent node
            dfs(neighbor, node, adj, subtreeSum);  // Recursively calculate subtree sum for the child
            subtreeSum[node] += subtreeSum[neighbor];  // Add the child's subtree sum to this node's sum
        }
    }
}

int main() {
    // Hardcoded number of nodes
    int N = 7;

    // Hardcoded edges for the tree
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 4},
        {2, 5},
        {2, 3},
        {2, 6},
        {4, 7}
    };

    vector<vector<int>> adj(N + 1); // Adjacency list (1-based indexing)

    // Build the adjacency list from the hardcoded edges
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> subtreeSum(N + 1, 0); // To store the subtree sum of each node

    // Perform DFS starting from node 1 (root node), with parent as -1 (since root has no parent)
    dfs(1, -1, adj, subtreeSum);

    // Output the subtree sums for nodes from 1 to N
    cout << "Subtree sums:" << endl;
    for (int i = 1; i <= N; ++i) {
        cout << "Node " << i << ": " << subtreeSum[i] << endl;
    }

    return 0;
}

/*
The edges represent the following tree:
        1
       / \
      2   4
     /|   |
    3 5   7
    |
    6
*/
