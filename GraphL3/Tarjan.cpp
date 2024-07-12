#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tarjan {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis,
             vector<vector<int>>& adj, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (int it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n, 0);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;

        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Tarjan obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, edges);

    for (auto& bridge : bridges) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "] ";
    }
    cout << endl;

    return 0;
}
