#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the shortest path between node x and node y using BFS
int shortestPathLength(int n, vector<pair<int, int>>& edges, int x, int y) {
    // Create an adjacency list for the graph
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    // Vector to store the distance from node x to each node
    vector<int> dist(n + 1, INT_MAX);
    dist[x] = 0; // Distance from x to itself is 0

    // Queue for BFS
    queue<int> q;
    q.push(x);

    // Perform BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Visit all adjacent nodes
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) {
                // Update the distance to this neighbor
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Return the distance to node y if reachable, otherwise return -1
    return (dist[y] == INT_MAX) ? -1 : dist[y];
}

int main() {
    int n, m;
    cin >> n >> m;  // n is the number of nodes, m is the number of edges
    
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    int x, y;
    cin >> x >> y;  // Start and end nodes

    int result = shortestPathLength(n, edges, x, y);

    cout << result << endl;

    return 0;
}


/*
5 6
1 2
2 3
1 3
3 5
2 4
4 5
2 5

*/