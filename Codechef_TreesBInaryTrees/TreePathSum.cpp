#include <bits/stdc++.h>

using namespace std;


bool dfs(int s, int currentSum, int targetSum,
    const vector < vector < int >> & adj, vector < bool > & visited) {
    visited[s] = true;
    currentSum += s;
    bool isLeaf = true;
    for (int it: adj[s]) {
        if (visited[it] == false) {
            if (dfs(it, currentSum, targetSum, adj, visited)) {
                return true;
            }
        }
    }
    if (isLeaf && currentSum == targetSum) {
        return true;
    }

    return false;
}
int main() {
    int N, targetSum;
    cin >> N >> targetSum;

    vector < vector < int >> adj(N + 1); // Adjacency list representation of the tree

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector < bool > visited(N + 1, false); // To track visited nodes

    // Start DFS from the root (node 1) with an initial sum of 0
    bool hasPath = dfs(1, 0, targetSum, adj, visited);

    if (hasPath) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


/*
7 12
1 2
1 4
2 5
2 3
2 6
4 7
*/