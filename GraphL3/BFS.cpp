#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal from node 0
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V, 0); // visited array
    queue<int> q;

    vis[0] = 1; // mark the starting node (0) as visited
    q.push(0);  // enqueue the starting node

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return bfs;
}

// Function to add an undirected edge between u and v
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the BFS traversal result
void printAns(const vector<int>& ans) {
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<int> adj[6]; // Array of adjacency lists

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(V, adj);
    printAns(ans);

    return 0;
}
