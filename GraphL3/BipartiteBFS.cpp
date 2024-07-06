#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BipartiteBFS {
public:
    bool isBipartite(int V, vector<vector<int>>& adj) {
        vector<int> color(V, -1); // Initialize color array, -1 means uncolored

        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) { // If vertex i is uncolored
                if (!check(i, V, adj, color)) { // Check if it's not bipartite
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool check(int s, int V, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.push(s);
        color[s] = 0; // Color vertex s with 0 (first color)

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int it : adj[node]) {
                if (color[it] == -1) { // If neighbor it is uncolored
                    color[it] = 1 - color[node]; // Assign opposite color
                    q.push(it);
                } else if (color[it] == color[node]) { // If neighbor has same color
                    return false; // Not bipartite
                }
            }
        }
        return true; // Bipartite
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2, 5};
    adj[5] = {3, 4};

    BipartiteBFS obj;
    bool ans = obj.isBipartite(V, adj);

    if (ans) {
        cout << "Bipartite" << endl;
    } else {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}
