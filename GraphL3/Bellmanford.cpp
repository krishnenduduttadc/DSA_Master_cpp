#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int s) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[s] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != numeric_limits<int>::max() && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != numeric_limits<int>::max() && dist[u] + wt < dist[v]) {
            // Negative cycle detected
            return vector<int>(1, -1);
        }
    }

    return dist;
}

int main() {
    int V = 6;
    int s = 0;
    vector<vector<int>> edges = {
        {3, 2, 6},
        {5, 3, 1},
        {0, 1, 5},
        {1, 5, -3},
        {1, 2, -2},
        {3, 4, -2},
        {2, 4, 3}
    };

    vector<int> dist = bellmanFord(V, edges, s);

    cout << "Shortest distances from source vertex " << s << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
