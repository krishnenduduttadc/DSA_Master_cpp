#include <bits/stdc++.h>
using namespace std;

vector<int> parent, depth;

void dfs(int node, int par, const vector<vector<int>>& adj) {
    parent[node] = par; // Set the parent of the current node
    for (int neighbor : adj[node]) {
        if (neighbor != par) { // Don't go back to the parent
            depth[neighbor] = depth[node] + 1; // Set the depth of the child node
            dfs(neighbor, node, adj); // Recursively process the subtree
        }
    }
}

// Function to find LCA of nodes u and v
int findLCA(int u, int v) {
    // Step 1: Lift u and v to the same depth
    if (depth[u] < depth[v]) swap(u, v); // Make sure u is the deeper node
    
    // Lift u up to the same depth as v
    while (depth[u] > depth[v]) {
        u = parent[u];
    }

    // Step 2: Move both u and v upwards until they meet
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u; // This is the LCA
}

int main() {
    // Hardcoded input for the number of nodes and the two nodes to find LCA
    int n = 7; // Number of nodes
    int u = 3, v = 7; // Nodes for which to find LCA

    // Adjacency list for the tree
    vector<vector<int>> adj(n + 1);

    // Hardcoded edges of the tree
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 4},
        {2, 5},
        {2, 3},
        {2, 6},
        {4, 7}
    };

    // Build the tree from hardcoded edges
    for (const auto& edge : edges) {
        int ui = edge.first;
        int vi = edge.second;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    // Initialize the parent and depth arrays
    parent.resize(n + 1);
    depth.resize(n + 1, 0);

    // Perform DFS from node 1 (root of the tree) to calculate parent and depth for each node
    dfs(1, -1, adj);

    // Find and print the LCA of u and v
    int lca = findLCA(u, v);
    cout << lca << endl;

    return 0;
}

/*
Expected Output:
1
*/
