#include <iostream>
#include <vector>

using namespace std;

class CycleDirectedDFS {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int> vis, vector<int> pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        // Traverse for adjacent nodes
        for (int it : adj[node]) {
            // When the node is not visited
            if (vis[it] == 0) {
                if (dfsCheck(it, adj, vis, pathVis))
                    return true;
            }
            // If the node has been previously visited
            // but it has to be visited on the same path
            else if (pathVis[it] == 1) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfsCheck(i, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 11;
    vector<vector<int>> adj(V);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(7);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[7].push_back(5);
    adj[8].push_back(9);
    adj[9].push_back(10);
    adj[10].push_back(8);

    CycleDirectedDFS obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
