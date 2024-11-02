#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input for testing
    int n = 6; // Number of nodes in the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5}
    };

    // This is our adjacency matrix
    // All the elements are initialized to zero
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Adding edges to the adjacency matrix
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // Adding an edge from u to v
        adjMatrix[u][v] = 1;
    }

    // Printing the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
