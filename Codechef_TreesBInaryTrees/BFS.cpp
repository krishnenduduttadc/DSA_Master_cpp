#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input for testing
    int n = 10; // Number of nodes in the tree
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {5, 9},
        {3, 6},
        {3, 7},
        {6, 10},
        {4, 8}
    };

    // Adjacency list representation of the tree
    vector<vector<int>> tree(n + 1); // +1 to accommodate 1-based indexing

    // Adding edges to the adjacency list
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    deque<int> q;
    vector<bool> visited(n + 1, false); // +1 to accommodate 1-based indexing
    q.push_back(1);
    visited[1] = true;

    while (!q.empty()) {
        int rem = q.front();
        q.pop_front();

        cout << rem << " ";

        for (int i : tree[rem]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push_back(i);
            }
        }
    }
    cout << endl;

    return 0;
}
