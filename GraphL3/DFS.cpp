#include <iostream>
#include <vector>

using namespace std;

class DFS {
public:
    void dfs(int s, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& ls) {
        vis[s] = true;
        ls.push_back(s);
        for (int it : adj[s]) {
            if (!vis[it]) {
                dfs(it, vis, adj, ls);
            }
        }
    }
};

int main() {
    int V = 5;
    vector<bool> vis(V, false);
    vector<int> ls;
    vector<vector<int>> adj(V);
    
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[2].push_back(4);
    adj[4].push_back(2);

    vector<vector<int>> res;
    DFS dfsSolver;
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            vector<int> ls;
            dfsSolver.dfs(i, vis, adj, ls);
            res.push_back(ls);
        }
    }
    
    for (const auto& component : res) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
