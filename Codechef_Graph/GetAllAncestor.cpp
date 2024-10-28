#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Hardcoded input: number of nodes and edges
    int n = 5;  // Number of nodes
    int m = 6;  // Number of edges
    
    // Hardcoded edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2},
        {2, 4},
        {1, 3},
        {3, 4}
    };

    // Initialize adjacency list and indegree array
    vector<int> adjList[n];
    vector<int> indegree(n, 0);
    
    // Prepare adjacency list and indegree array from hardcoded edges
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    // Insert nodes with zero indegree into queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<set<int>> ancestors(n);  // Store ancestors for each node
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adjList[u]) {
            // Add u and all its ancestors to v's ancestor set
            ancestors[v].insert(u);
            ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());
            
            // Decrement indegree and if it becomes zero, add to queue
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Output ancestors in sorted order for each node
    for (int i = 0; i < n; i++) {
        cout << "Ancestors of node " << i << ": ";
        for (int ancestor : ancestors[i]) {
            cout << ancestor << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
Expected Output:
Ancestors of node 0: 
Ancestors of node 1: 0 
Ancestors of node 2: 0 1 
Ancestors of node 3: 1 
Ancestors of node 4: 0 1 2 3 
*/
