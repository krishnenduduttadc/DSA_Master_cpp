#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <climits>

using namespace std;

// Class representing a Pair for priority queue
class Pair {
public:
    int vtx, wsf;

    Pair(int vtx, int wsf) {
        this->vtx = vtx;
        this->wsf = wsf;
    }

    // Comparator for priority queue
    bool operator>(const Pair& other) const {
        return this->wsf > other.wsf;
    }
};

// Function to find the shortest distance of all vertices from source vertex S using Dijkstra's algorithm
vector<int> dijkstra(int V, vector<vector<vector<int>>>& adj, int S) {
    vector<int> ans(V, INT_MAX);
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    // Start with the source vertex S with weight 0.
    pq.push(Pair(S, 0));

    while (!pq.empty()) {
        Pair rem = pq.top();
        pq.pop();

        // If we have already processed this vertex, continue.
        if (ans[rem.vtx] != INT_MAX) continue;

        // Update the shortest distance to this vertex.
        ans[rem.vtx] = rem.wsf;

        // Traverse all neighboring vertices.
        for (vector<int>& edge : adj[rem.vtx]) {
            int nbr = edge[0];
            int wt = edge[1];

            // If the neighboring vertex has not been visited, add it to the priority queue.
            if (ans[nbr] == INT_MAX) {
                pq.push(Pair(nbr, rem.wsf + wt));
            }
        }
    }

    return ans;
}

int main() {
    // Example graph representation using adjacency list

    // Number of vertices
    int V = 6;

    // Adjacency list representation of the graph
    vector<vector<vector<int>>> adj(V);
    for (int i = 0; i < V; i++) {
        adj[i] = vector<vector<int>>();
    }

    // Adding edges to the graph
    adj[0].push_back({1, 2}); // Edge from vertex 0 to vertex 1 with weight 2
    adj[0].push_back({2, 4}); // Edge from vertex 0 to vertex 2 with weight 4
    adj[1].push_back({2, 1}); // Edge from vertex 1 to vertex 2 with weight 1
    adj[1].push_back({3, 7}); // Edge from vertex 1 to vertex 3 with weight 7
    adj[2].push_back({3, 3}); // Edge from vertex 2 to vertex 3 with weight 3
    adj[3].push_back({4, 2}); // Edge from vertex 3 to vertex 4 with weight 2
    adj[4].push_back({5, 5}); // Edge from vertex 4 to vertex 5 with weight 5

    // Source vertex for Dijkstra's algorithm
    int sourceVertex = 0;

    // Call Dijkstra's algorithm to find shortest paths from sourceVertex
    vector<int> shortestDistances = dijkstra(V, adj, sourceVertex);

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << sourceVertex << ": " << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
