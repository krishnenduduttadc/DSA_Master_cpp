#include <bits/stdc++.h>
using namespace std;

bool detect(int s, vector<int> adj[], int vis[]) {
    vis[s] = 1;
    queue<pair<int, int>> q;
    q.push({s, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, node});
            } else if (parent != it) {
                // Found a cycle
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detect(i, adj, vis))
                return true;
        }
    }

    return false;
}

int main() {
    // V = 4, E = 2
    vector<int> adj[4] = {
        {},       // 0
        {2},      // 1
        {1, 3},   // 2
        {2}       // 3
    };

    bool ans = isCycle(4, adj);
    cout << (ans ? "1\n" : "0\n");

    return 0;
}
