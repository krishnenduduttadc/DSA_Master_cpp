#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to perform DFS and mark visited nodes
    void dfs(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
        visited[node] = true; // Mark the current node as visited
        for (int v : adjList[node]) { // Iterate over all neighbors of the current node
            if (!visited[v]) { // If a neighbor has not been visited
                dfs(v, adjList, visited); // Recursively perform DFS on the neighbor
            }
        }
    }

    // Function to count the number of connected components
    int countComponents(int n, int m, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n + 1); // Adjacency list to store the graph
        vector<bool> visited(n + 1, false); // Array to keep track of visited nodes
        
        // Build the adjacency list from the edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v); // Add edge from u to v
            adjList[v].push_back(u); // Add edge from v to u (undirected graph)
        }
        
        int components = 0; // Variable to count the number of connected components
        
        // Iterate through all nodes to count connected components
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) { // If the node has not been visited
                dfs(i, adjList, visited); // Perform DFS to visit all nodes in the component
                ++components; // Increment the count of connected components
            }
        }
        
        return components; // Return the number of connected components
    }
};

int main() {
    int n, m;
    cin >> n >> m; // Read number of nodes and number of edges
    
    vector<vector<int>> edges(m, vector<int>(2));
    
    // Read the edges
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    Solution sol; // Create an instance of the Solution class
    int result = sol.countComponents(n, m, edges); // Find the number of connected components
    cout << result << endl; // Output the result
    
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