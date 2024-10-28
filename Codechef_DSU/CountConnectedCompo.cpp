#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int setSize[100000];

int dsuFind(int a) {
    if (parent[a] == a) return a; // If a is the root
    return parent[a] = dsuFind(parent[a]); // Path compression
}

void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if (leader_a != leader_b) {
        // Union by size
        if (setSize[leader_b] < setSize[leader_a]) {
            swap(leader_a, leader_b);
        }
        parent[leader_a] = leader_b; // Attach smaller tree to larger tree
        setSize[leader_b] += setSize[leader_a]; // Update the size
    }
}

int main() {
    // Hardcoded input
    int n = 10; // Number of nodes
    int m = 5;  // Number of edges

    // Initialize parent and setSize arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is its own parent initially
        setSize[i] = 1; // Each component is of size 1 initially
    }

    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    // Perform union operations
    for (const auto& edge : edges) {
        dsuUnion(edge.first, edge.second);
    }

    // Count the number of unique leaders (connected components)
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (dsuFind(i) == i) count++; // Count roots
    }

    cout << count << endl; // Output the number of connected components
    return 0;
}
