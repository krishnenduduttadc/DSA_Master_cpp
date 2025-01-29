#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> dfs(int node, vector<int> adj[], vector<int> vis) {
        vis[node] = 1;
        vector<int> ls;
        ls.push_back(node);
        
        // Traverse all its neighbors
        for (auto it : adj[node]) {
            if (!vis[it]) {
                // Recursively visit unvisited neighbors
                vector<int> subResult = dfs(it, adj, vis);
                ls.insert(ls.end(), subResult.begin(), subResult.end());
            }
        }
        return ls;
    }
  
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);  // Visited array
        int start = 0;          // Start node for DFS
        
        // Call DFS starting from node 0
        return dfs(start, adj, vis);
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> adj[5];
    
    // Add edges to the graph
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    // Create Solution object and get DFS traversal result
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    
    // Print the DFS traversal result
    printAns(ans);

    return 0;
}
