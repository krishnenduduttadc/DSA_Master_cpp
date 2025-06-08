#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<bool> vis;
vector<int> disc;
vector<int> low;
int timeDFS = 0;

vector<vector<int>> bridges(const vector<list<int>>& graph, int src, int par) {
    vis[src] = true;
    disc[src] = low[src] = ++timeDFS;

    vector<vector<int>> ans;

    for (int nbr : graph[src]) {
        if (nbr == par) continue;
        if (!vis[nbr]) {
            vector<vector<int>> childBridges = bridges(graph, nbr, src);
            ans.insert(ans.end(), childBridges.begin(), childBridges.end());

            low[src] = min(low[src], low[nbr]);

            if (low[nbr] > disc[src]) {
                ans.push_back({src, nbr});
            }
        } else {
            low[src] = min(low[src], disc[nbr]);
        }
    }

    return ans;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
    vector<vector<int>> ans;
    vector<list<int>> graph(n);

    // Construct adjacency list
    for (auto& connection : connections) {
        int u = connection[0];
        int v = connection[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Initialize arrays for DFS
    vis.assign(n, false);
    disc.assign(n, -1);
    low.assign(n, -1);
    timeDFS = 0;

    // Finding bridges using DFS
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<vector<int>> bridgesResult = bridges(graph, i, -1);
            ans.insert(ans.end(), bridgesResult.begin(), bridgesResult.end());
        }
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3},
        {3, 4}
    };

    vector<vector<int>> criticalConns = criticalConnections(n, connections);

    cout << "Critical Connections (Bridges):" << endl;
    for (const auto& connection : criticalConns) {
        cout << connection[0] << " - " << connection[1] << endl;
    }

    return 0;
}
