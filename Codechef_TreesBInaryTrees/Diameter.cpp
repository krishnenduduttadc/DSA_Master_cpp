#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and return the farthest node and its distance
pair<int, int> dfs(int node, int parent, const vector<vector<int>>& adj) {
    pair<int, int> farthest = {node, 0}; // {farthest_node, max_distance}

    // Traverse all neighbors
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {  // Avoid going back to the parent
            pair<int, int> res = dfs(neighbor, node, adj);
            res.second++; // Increment the distance by 1 as we go deeper
            if (res.second > farthest.second) {
                farthest = res; // Update farthest node and distance
            }
        }
    }

    return farthest;
}

int main() {
    int n;
    cin >> n; // Read the number of nodes

    vector<vector<int>> adj(n + 1); // Adjacency list (1-based indexing)

    // Read the edges and construct the adjacency list
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 1: Find the farthest node from any arbitrary node (e.g., node 1)
    pair<int, int> farthest_from_1 = dfs(1, -1, adj);

    // Step 2: Find the farthest node from the node found in Step 1
    pair<int, int> farthest_from_A = dfs(farthest_from_1.first, -1, adj);

    // The distance to the farthest node from A is the diameter
    int diameter = farthest_from_A.second;

    cout << diameter << endl;

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