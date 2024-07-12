#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
    vis[node] = 1; // Mark the node as visited

    // Traverse all adjacent nodes
    for (int it : adjLs[node]) {
        if (vis[it] == 0) { // If adjacent node is not visited, recursively call DFS
            dfs(it, adjLs, vis);
        }
    }
}

// Function to count the number of provinces (connected components)
int numProvinces(vector<vector<int>>& adj, int V) {
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjLs(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // Self loops are not considered
            if (adj[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0); // Array to mark visited nodes
    int cnt = 0; // Initialize count of provinces

    // Perform DFS for each node
    for (int i = 0; i < V; i++) {
        if (vis[i] == 0) { // If node is not visited, it's a new province
            cnt++;
            dfs(i, adjLs, vis); // Perform DFS to mark all reachable nodes
        }
    }

    return cnt; // Return the number of provinces
}

int main() {
    // Example adjacency matrix representation of graph
    vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = adj.size(); // Number of vertices

    // Call function to find number of provinces
    int numProvincesCount = numProvinces(adj, V);

    cout << "Number of provinces: " << numProvincesCount << endl;

    return 0;
}
