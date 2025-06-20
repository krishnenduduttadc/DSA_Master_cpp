#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSR(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << " ";

    for (int nbr : adj[s]) {
        if (!visited[nbr]) {
            DFSR(adj, nbr, visited);
        }
    }
}

void DFS(vector<vector<int>>& adj, int V, int s) {
    vector<bool> visited(V, false);
    DFSR(adj, s, visited);
}

int main() {
    int V = 7; // Number of vertices
    vector<vector<int>> adj(V); // Adjacency list representation of the graph

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 4);

    cout << "Following is Depth First Traversal:" << endl;
    DFS(adj, V, 0); // Starting DFS traversal from vertex 0

    return 0;
}
