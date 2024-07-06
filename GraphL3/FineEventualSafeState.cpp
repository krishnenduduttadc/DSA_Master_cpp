#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class EventualSafeState {
public:
    vector<int> eventualSafeNodes(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        vector<int> safeNodes;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }

private:
    bool dfsCheck(int s, vector<vector<int>>& adj, vector<int>& vis,
                  vector<int>& pathVis, vector<int>& check) {
        vis[s] = 1;
        pathVis[s] = 1;
        check[s] = 0;
        for (int it : adj[s]) {
            if (vis[it] == 0) {
                if (dfsCheck(it, adj, vis, pathVis, check)) {
                    return true;
                }
            } else if (pathVis[it] == 1) {
                return true;
            }
        }
        check[s] = 1;
        pathVis[s] = 0;
        return false;
    }
};

int main() {
    int V = 12;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[6].push_back(7);
    adj[8].push_back(1);
    adj[8].push_back(9);
    adj[9].push_back(10);
    adj[10].push_back(8);
    adj[11].push_back(9);

    EventualSafeState obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
