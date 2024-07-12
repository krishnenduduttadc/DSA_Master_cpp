#include <iostream>
#include <vector>
using namespace std;

class ArticulationPoint {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis,
             vector<int>& tin, vector<int>& low,
             vector<int>& mark, vector<vector<int>>& adj) {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for (int it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<vector<int>>& adj) {
        vector<int> vis(n, 0), tin(n, -1), low(n, -1), mark(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.empty()) {
            ans.push_back(-1);
        }
        return ans;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4},
        {2, 4}, {2, 3}, {3, 4}
    };
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ArticulationPoint obj;
    vector<int> nodes = obj.articulationPoints(n, adj);

    for (int node : nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
