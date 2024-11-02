#include <bits/stdc++.h>
using namespace std;

void dfs(int s, const vector<vector<int>>& adjList, vector<bool>& visited, int& leafCount) {
    visited[s] = true;
    bool isLeaf = true;

    // Traverse all connected nodes
    for (int it : adjList[s]) {
        if (!visited[it]) { // Continue DFS if the node is unvisited
            isLeaf = false; // Current node is not a leaf if it has unvisited neighbors
            dfs(it, adjList, visited, leafCount);
        }
    }

    if (isLeaf) { // If node is a leaf, increment leafCount
        leafCount++;
    }
}

int main() {
    int N = 8; // Number of nodes

    // Hardcoded adjacency list based on edges
    vector<vector<int>> adjList(N);
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 6}, {5, 7}
    };

    for (auto edge : edges) {
        int a = edge.first, b = edge.second;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<bool> visited(N, false);
    int leafCount = 0;

    // Start DFS from node 0
    dfs(0, adjList, visited, leafCount);

    // Output the total number of leaf nodes
    cout << leafCount << endl;

    return 0;
}
