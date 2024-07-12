#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class NumberofWaystoArriveatDestination {
public:
    struct Pair {
        int first;
        int second;

        Pair(int f, int s) : first(f), second(s) {}
    };

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<Pair>> adj(n);

        for (auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        vector<int> dist(n, INT_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};

int main() {
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
        {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };

    NumberofWaystoArriveatDestination obj;
    int ans = obj.countPaths(n, roads);

    cout << ans << endl;

    return 0;
}
