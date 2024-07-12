#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BFS {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
        vector<int> bfs;
        vector<bool> vis(V, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }

        return bfs;
    }
};

int main() {
    vector<vector<int>> adj(5);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(4);
    adj[4].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);

    BFS sl;
    vector<int> ans = sl.bfsOfGraph(5, adj);
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}
