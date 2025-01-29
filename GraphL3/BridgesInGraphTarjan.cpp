#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;
    vector<int> tin, low, vis;
    
    vector<vector<int>> dfs(int node, int parent, vector<vector<int>> adj) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        vector<vector<int>> bridges;
        
        for (int it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                vector<vector<int>> childBridges = dfs(it, node, adj);
                bridges.insert(bridges.end(), childBridges.begin(), childBridges.end());
                low[node] = min(low[it], low[node]);
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
        return bridges;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
        vector<vector<int>> adj(n);
        for (vector<int> it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        tin.assign(n, 0);
        low.assign(n, 0);
        vis.assign(n, 0);
        
        return dfs(0, -1, adj);
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    for (vector<int> it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
