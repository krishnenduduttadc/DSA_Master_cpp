#include <iostream>
#include <vector>
using namespace std;

class BipartiteDFS {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        color[node] = col;

        // Traverse adjacent nodes
        for (int it : adj[node]) {
            // If uncolored
            if (color[it] == -1) {
                if (!dfs(it, 1 - col, color, adj)) return false;
            }
            // If previously colored and have the same color
            else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        vector<int> color(V, -1);

        // For connected components
        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, adj)) return false;
            }
        }
        return true;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    BipartiteDFS obj;
    bool ans = obj.isBipartite(V, adj);

    if (ans) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
