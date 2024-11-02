#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int currentLevel, int k,
    vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[s] = true;
    if (currentLevel == k) {
        result.push_back(s); // If we are at the required level, store the node
    }
    for (int it : adj[s]) {
        if (!visited[it]) {
            dfs(it, currentLevel + 1, k, adj, visited, result);
        }
    }
}

int main() {
    int n = 8; // Number of nodes
    int k = 2; // Desired level

    // Hardcoded adjacency list based on edges
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}, {2, 7}, {2, 8}
    };

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    vector<int> result;

    // Start DFS from node 1 to find all nodes at level `k`
    dfs(1, 0, k, adj, visited, result);

    // Sort and output the result
    sort(result.begin(), result.end());
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
