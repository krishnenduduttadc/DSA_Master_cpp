#include <bits/stdc++.h>

using namespace std;


void dfs(int s, int currentLevel, int k,
    vector < vector < int >> & adj, vector < bool > & visited, vector < int > & result) {
    visited[s] = true;
    if (currentLevel == k) {

        result.push_back(s);
    }
    for (int it: adj[s]) {
        if (visited[it] == false) {
            dfs(it, currentLevel + 1, k, adj, visited, result);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k; // Read number of nodes and level K

    vector < vector < int >> adj(n + 1); // Using 1-based indexing for nodes

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; // Read each edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector < bool > visited(n + 1, false);
    vector < int > result; // Visited array

    // Print nodes at level K
    //cout << "Nodes at level " << k << ": ";
    dfs(1, 0, k, adj, visited, result); // Start DFS from node 1 with current level 
    sort(result.begin(), result.end());
    for (int node: result) {
        cout << node << " ";
    }
    cout << endl;
}


/*
8 2
1 2
1 3
3 4
3 5
3 6
2 7 
2 8

*/