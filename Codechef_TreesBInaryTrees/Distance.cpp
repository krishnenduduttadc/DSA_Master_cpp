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

// Function to find the distance between nodes u and v
int findDistance(int u, int v) {
    int lca = findLCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main() {
    int n, u, v;
    cin >> n >> u >> v; // Read number of nodes, and the nodes u and v

    vector<vector<int>> adj(n + 1); // Adjacency list for the tree

    // Read the edges and build the tree
    for (int i = 1; i < n; i++) {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }

    // Initialize the parent and depth arrays
    parent.resize(n + 1);
    depth.resize(n + 1, 0);

    // Perform DFS from node 1 (root of the tree) to calculate parent and depth for each node
    dfs(1, -1, adj);

    // Calculate and print the distance between u and v
    int distance = findDistance(u, v);
    cout  << distance << endl;

    return 0;
}



/*
7 3 7
1 2
1 4
2 5
2 3
2 6
4 7

*/