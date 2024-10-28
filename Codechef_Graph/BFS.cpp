#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, vector<bool>& visited, vector<vector<int>>& adjList) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // Process nodes in the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Enqueue unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Hardcoded number of nodes and edges
    int numNodes = 4;
    int numEdges = 5;

    // Initialize adjacency list
    vector<vector<int>> adjList(numNodes + 1); // 1-based index

    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 4},
        {1, 3}
    };

    // Adding edges to the graph
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Perform BFS starting from node 1
    vector<bool> visited(numNodes + 1, false);
    cout << "BFS traversal: ";
    bfs(1, visited, adjList);

    return 0;
}

/*
Expected Output:
BFS traversal: 1 2 3 4 
*/
