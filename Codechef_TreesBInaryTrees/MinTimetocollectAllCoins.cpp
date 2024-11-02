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
    int n = 7; // Number of nodes

    // Hardcoded coin information (1 if the node has a coin, 0 otherwise)
    hasCoin = {0, 0, 0, 1, 1, 1, 0, 0}; // Using 1-based indexing

    // Build the tree with hardcoded edges
    adj.resize(n + 1);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[3].push_back(6); adj[6].push_back(3);
    adj[3].push_back(7); adj[7].push_back(3);

    // Start DFS from the root node (1) and calculate the total time
    int totalTime = dfs(1, -1); // Root has no parent, so we pass -1

    // Output the total time required to collect all coins and return to the root
    cout << totalTime << endl;

    return 0;
}
