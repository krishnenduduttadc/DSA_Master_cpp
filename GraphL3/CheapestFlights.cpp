#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class CheapestFlights {
public:
    struct Pair {
        int first, second;
        Pair(int f, int s) : first(f), second(s) {}
    };

    struct Tuple2 {
        int first, second, third;
        Tuple2(int f, int s, int t) : first(f), second(s), third(t) {}
    };

    int CheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<Pair>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<Tuple2> q;
        q.emplace(0, src, 0);

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > K) continue;
            for (const auto& [adjNode, edW] : adj[node]) {
                if (cost + edW < dist[adjNode] && stops <= K) {
                    dist[adjNode] = cost + edW;
                    q.emplace(stops + 1, adjNode, cost + edW);
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    int n = 4, src = 0, dst = 3, K = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    CheapestFlights obj;
    int ans = obj.CheapestFlight(n, flights, src, dst, K);

    cout << ans << endl;

    return 0;
}
