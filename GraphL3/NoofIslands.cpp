#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class NoofIslands {
public:
    // Function to return Breadth First Traversal of given graph.
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

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent has not been visited, then mark it
            // visited and enqueue it
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
    vector<vector<int>> adj = {
        {1, 4},
        {0, 2, 3},
        {1},
        {1},
        {0}
    };

    NoofIslands sl;
    vector<int> ans = sl.bfsOfGraph(5, adj);
    int n = ans.size();
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
