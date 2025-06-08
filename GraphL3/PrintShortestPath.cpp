#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n + 1];
    for (auto &it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        for (auto &adjPair : adj[node]) {
            int adjNode = adjPair.first;
            int edW = adjPair.second;

            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == 1e9) return {-1};

    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    vector<int> path = shortestPath(V, E, edges);

    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
