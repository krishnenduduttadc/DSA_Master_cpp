#include <bits/stdc++.h>

using namespace std;

int dfs(int s, vector < vector < int >> & adj, vector < bool > & visited) {
    visited[s] = true;
    int maxHeight = 0;
    for (int it: adj[s]) {
        if (visited[it] == false) {
            int childheight = dfs(it, adj, visited);
            maxHeight = max(maxHeight, childheight);
        }
    }
    return maxHeight + 1;
}
int main() {
    int n;
    cin >> n; // Read the number of vertices
    vector < vector < int >> adj(n + 1); // Adjacency list to store graph

    // Read the edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector < bool > visited(n + 1, false);
    int height = dfs(1, adj, visited) - 1; // Subtract 1 because the root node itself doesn't add to height
    cout << height << endl;

}

/*

8
1 2
1 3
3 4
3 5
3 6
2 7 
2 8
*/