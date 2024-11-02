#include <bits/stdc++.h>

using namespace std;

bool dfs(int s, int currentSum, int targetSum,
    const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[s] = true;
    currentSum += s;
    bool isLeaf = true;

    for (int it : adj[s]) {
        if (!visited[it]) {
            isLeaf = false; // Current node has children
            if (dfs(it, currentSum, targetSum, adj, visited)) {
                return true; // Found a valid path
            }
        }
    }

    if (isLeaf && currentSum == targetSum) {
        return true; // Found a valid leaf node with the target sum
    }

    return false; // No valid path found
}

int main() {
    int N = 7; // Number of nodes
    int targetSum = 12; // Target sum

    // Hardcoded edges for the tree
    vector<vector<int>> adj(N + 1); // Adjacency list representation of the tree
    adj[1] = {2, 4}; // Node 1 connected to 2 and 4
    adj[2] = {1, 5, 3, 6}; // Node 2 connected to 1, 5, 3, and 6
    adj[3] = {2}; // Node 3 connected to 2
    adj[4] = {1, 7}; // Node 4 connected to 1 and 7
    adj[5] = {2}; // Node 5 connected to 2
    adj[6] = {2}; // Node 6 connected to 2
    adj[7] = {4}; // Node 7 connected to 4

    vector<bool> visited(N + 1, false); // To track visited nodes

    // Start DFS from the root (node 1) with an initial sum of 0
    bool hasPath = dfs(1, 0, targetSum, adj, visited);

    if (hasPath) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
