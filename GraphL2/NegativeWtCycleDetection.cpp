#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool isNegativeWeightCycle(int n, vector<Edge>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0; // Starting from vertex 0

    // Relaxation process
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Checking for negative weight cycles
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            return true; // Negative weight cycle detected
        }
    }

    return false; // No negative weight cycle found
}

int main() {
    // Hardcoded input
    int n = 3; // Number of vertices
    int m = 3; // Number of edges
    vector<Edge> edges = {{0, 1, -1}, {1, 2, -4}, {2, 0, 3}}; // Edges with (u, v, weight)

    if (isNegativeWeightCycle(n, edges)) {
        cout << "1\n"; // Negative weight cycle detected
    } else {
        cout << "0\n"; // No negative weight cycle found
    }

    return 0;
}
