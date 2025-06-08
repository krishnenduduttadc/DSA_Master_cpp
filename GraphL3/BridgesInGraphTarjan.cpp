#include <bits/stdc++.h>
using namespace std;

int timer;
vector<int> tin, low, vis;

vector<vector<int>> dfs(int node, int parent, vector<vector<int>> &adj) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    vector<vector<int>> bridges;

    for (int it : adj[node]) {
        if (it == parent) continue;
        if (!vis[it]) {
            vector<vector<int>> childBridges = dfs(it, node, adj);
            bridges.insert(bridges.end(), childBridges.begin(), childBridges.end());
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                bridges.push_back({it, node});
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }
    return bridges;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
    vector<vector<int>> adj(n);
    for (auto &conn : connections) {
        int u = conn[0], v = conn[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tin.assign(n, 0);
    low.assign(n, 0);
    vis.assign(n, 0);
    timer = 1;

    return dfs(0, -1, adj);
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    vector<vector<int>> bridges = criticalConnections(n, connections);

    for (auto &bridge : bridges) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "] ";
    }
    cout << endl;

    return 0;
}
