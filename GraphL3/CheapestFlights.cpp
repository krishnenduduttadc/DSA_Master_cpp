#include <bits/stdc++.h>
using namespace std;

int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    vector<pair<int, int>> adj[n];
    for (auto &it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q; // {stops, {node, cost}}
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > K) continue;

        for (auto &iter : adj[node]) {
            int adjNode = iter.first;
            int edW = iter.second;

            if (cost + edW < dist[adjNode] && stops <= K) {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    return (dist[dst] == 1e9) ? -1 : dist[dst];
}

int main() {
    int n = 4, src = 0, dst = 3, K = 1;
    vector<vector<int>> flights = {
        {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}
    };

    int ans = CheapestFlight(n, flights, src, dst, K);
    cout << ans << endl;

    return 0;
}
