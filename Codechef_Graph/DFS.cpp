#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS
void dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    // Mark the current node as visited
    visited[node] = true;
    
    // Process the current node (print or do other operations)
    cout << node << " ";

    // Explore all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

// Function to initialize DFS and handle disconnected components
void performDFS(int numNodes, vector<vector<int>>& adjList) {
    vector<bool> visited(numNodes + 1, false);

    // Iterate through all nodes to handle disconnected components
    for (int i = 1; i <= numNodes; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjList);
        }
    }
}

int main() {
    // Hardcoded number of nodes and edges
    int numNodes = 4; // Number of nodes
    int numEdges = 5; // Number of edges

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

    // Perform DFS
    cout << "DFS traversal: ";
    performDFS(numNodes, adjList);

    return 0;
}

/*
Expected Output:
DFS traversal: 1 2 3 4 
*/
