#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class representing an Edge
class Edge {
public:
    int src, dest, weight;

    Edge(int src, int dest, int wt) {
        this->src = src;
        this->dest = dest;
        this->weight = wt;
    }

    // Comparator for sorting edges based on weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Kruskal {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    Kruskal(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find operation with path compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    // Union operation by rank
    void unionByRank(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);

        if (uPar != vPar) {
            if (rank[uPar] < rank[vPar]) {
                parent[uPar] = vPar;
            } else if (rank[vPar] < rank[uPar]) {
                parent[vPar] = uPar;
            } else {
                parent[vPar] = uPar;
                rank[uPar]++;
            }
        }
    }

    // Union operation by size
    void unionBySize(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);

        if (uPar != vPar) {
            if (size[uPar] < size[vPar]) {
                parent[uPar] = vPar;
                size[vPar] += size[uPar];
            } else {
                parent[vPar] = uPar;
                size[uPar] += size[vPar];
            }
        }
    }

    // Function to find MST using Kruskal's algorithm
    int findMST(int V, vector<vector<pair<int, int>>>& adj) {
        vector<Edge> edges;

        // Convert adjacency list to edges with weights
        for (int i = 0; i < V; i++) {
            for (auto& neighbor : adj[i]) {
                int adjNode = neighbor.first;
                int wt = neighbor.second;
                edges.push_back(Edge(i, adjNode, wt));
            }
        }

        // Sort edges based on weight
        sort(edges.begin(), edges.end());

        int mstWt = 0;

        // Iterate through sorted edges and add to MST
        for (Edge& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int wt = edge.weight;

            if (findUPar(u) != findUPar(v)) {
                mstWt += wt;
                unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    int edges[][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    // Construct adjacency list
    for (int i = 0; i < 6; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Create Kruskal's MST instance
    Kruskal kruskal(V);
    int mstWt = kruskal.findMST(V, adj);

    // Print the sum of all edge weights in MST
    cout << "The sum of all the edge weights: " << mstWt << endl;

    return 0;
}
