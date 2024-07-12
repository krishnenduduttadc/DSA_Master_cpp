#include <iostream>
#include <vector>

using namespace std;

class CycleUndirectedDFS {
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        for (int it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, vis, adj))
                    return true;
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> adj(4);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    CycleUndirectedDFS obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "cycle exists" << endl;
    else
        cout << "cycle does not exist" << endl;

    return 0;
}
