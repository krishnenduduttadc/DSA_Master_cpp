#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class ShortestPathinUndirectedGraphUnitWeights {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int s) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist(n, INT_MAX);
        dist[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

int main() {
    int n = 9, m = 10;
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int s = 0;

    ShortestPathinUndirectedGraphUnitWeights obj;
    vector<int> res = obj.shortestPath(edges, n, m, s);

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
