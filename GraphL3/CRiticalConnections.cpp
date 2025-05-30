#include <iostream>
#include <vector>
#include <list>

using namespace std;

class CRiticalConnections {
private:
    vector<bool> vis;
    vector<int> disc;
    vector<int> low;
    int time = 0;

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections) {
        vector<vector<int>> ans;
        vector<list<int>> graph(n);

        // Construct adjacency list
        for (vector<int> connection : connections) {
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Initialize arrays for DFS
        vis.assign(n, false);
        disc.assign(n, -1);
        low.assign(n, -1);

        // Finding bridges using DFS
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<vector<int>> bridgesResult = bridges(graph, i, -1);
                ans.insert(ans.end(), bridgesResult.begin(), bridgesResult.end());
            }
        }

        return ans;
    }

private:
    vector<vector<int>> bridges(vector<list<int>> graph, int src, int par) {
        vis[src] = true;
        disc[src] = low[src] = ++time;

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
};

int main() {
    CRiticalConnections solution;

    // Example graph representation
    int n = 5;
    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3},
        {3, 4}
    };

    // Finding critical connections (bridges)
    vector<vector<int>> criticalConnections = solution.criticalConnections(n, connections);

    // Printing out the critical connections
    cout << "Critical Connections (Bridges):" << endl;
    for (vector<int> connection : criticalConnections) {
        cout << connection[0] << " - " << connection[1] << endl;
    }

    return 0;
}
