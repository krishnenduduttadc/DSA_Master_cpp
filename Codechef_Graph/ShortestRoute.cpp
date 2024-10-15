#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the minimum number of servers on the shortest path using BFS
int minServersOnRoute(int n, vector<pair<int, int>>& connections) {
    // Create an adjacency list for the graph
    vector<vector<int>> adj(n + 1);
    for (auto& conn : connections) {
        int u = conn.first;
        int v = conn.second;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

    // Vector to store the minimum distance from node 1 to each node
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;  // Distance to itself is 0

    // Queue for BFS
    queue<int> q;
    q.push(1);

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

    // Check if there's a path to node n
    if (dist[n] == INT_MAX) {
        return -1;  // No path exists
    } else {
        // The minimum number of servers is the number of nodes in the path, which is dist[n] + 1
        return dist[n] + 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        connections[i] = {u, v};
    }

    int result = minServersOnRoute(n, connections);
    
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

*/