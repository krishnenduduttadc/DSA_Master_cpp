#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list for the tree
vector<int> hasCoin;     // Array to store if the node has a coin

// DFS function to calculate time spent to collect all coins
int dfs(int node, int parent) {
    int timeSpent = 0; // Total time spent for this subtree

    // Traverse all the children of the current node
    for (int neighbor : adj[node]) {
        if (neighbor != parent) { // Avoid going back to the parent node
            int timeFromChild = dfs(neighbor, node); // DFS on the child
            if (timeFromChild > 0 || hasCoin[neighbor]) {
                // If the child subtree has coins, add time to go and return
                timeSpent += timeFromChild + 2;
            }
        }
    }
    
    return timeSpent; // Return the time spent in this subtree
}

int main() {
    int n;
    cin >> n; // Read the number of nodes

    // Read the coin information (1 if the node has a coin, 0 otherwise)
    hasCoin.resize(n + 1); // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> hasCoin[i];
    }

    // Build the tree
    adj.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from the root node (1) and calculate the total time
    int totalTime = dfs(1, -1); // Root has no parent, so we pass -1

    // Output the total time required to collect all coins and return to the root
    cout << totalTime << endl;

    return 0;
}



/*

7
0 0 1 1 1 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/