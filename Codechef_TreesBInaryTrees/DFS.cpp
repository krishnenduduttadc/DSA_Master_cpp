#include <bits/stdc++.h>
using namespace std;

const int maxx = 100005;
vector<int> tree[maxx];

void dfs(int node) {
    cout << node << " ";
    for (auto i: tree[node]) {
        dfs(i);
    }
}

int main() {
    // Hardcoded input
    int n = 10; // Number of nodes
    
    // Edges of the tree
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 5},
        {1, 9},
        {2, 3},
        {3, 4},
        {5, 6},
        {6, 7},
        {5, 8},
        {9, 10}
    };

    // Build the tree
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        tree[u].push_back(v);
    }
    
    // Start DFS from the root node
    dfs(1);

    return 0;
}
