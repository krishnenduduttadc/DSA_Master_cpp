#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class PrintShortestPath {
public:
    struct Pair {
        int first;
        int second;

        Pair(int first, int second) : first(first), second(second) {}
        
        // Define operator< for Pair to be used in priority_queue
        bool operator<(const Pair& other) const {
            return first > other.first; // Min-heap based on 'first'
        }
    };

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Create adjacency list representation of the graph
        vector<vector<Pair>> adj(n + 1);
        for (int i = 0; i <= n; ++i) {
            adj[i] = vector<Pair>();
        }
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(Pair(v, w));
            adj[v].push_back(Pair(u, w));
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<Pair> pq;

        // Distance array to store shortest distance from source (1) to each vertex
        vector<int> dist(n + 1, numeric_limits<int>::max());
        // Parent array to reconstruct shortest path
        vector<int> parent(n + 1);
        // Initialize distances to infinity and parent pointers to self
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Distance from source to itself is 0
        dist[1] = 0;
        // Add source vertex (1) to priority queue
        pq.push(Pair(0, 1));

        // Dijkstra's algorithm to compute shortest paths
        while (!pq.empty()) {
            Pair it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;

            // Iterate through all adjacent nodes of 'node'
            for (Pair& iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                // If a shorter path to 'adjNode' is found through 'node'
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push(Pair(dist[adjNode], adjNode));
                    parent[adjNode] = node;
                }
            }
        }

        // Reconstruct the shortest path from source (1) to destination (n)
        vector<int> path;
        if (dist[n] == numeric_limits<int>::max()) {
            path.push_back(-1); // If destination is unreachable
            return path;
        }

        int node = n;
        // Traverse back from destination to source using parent pointers
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); // Add the source vertex (1) to the path
        reverse(path.begin(), path.end()); // Reverse the path to get it in the correct order

        return path;
    }
};

int main() {
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    PrintShortestPath obj;
    vector<int> path = obj.shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
