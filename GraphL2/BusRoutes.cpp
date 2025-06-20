#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    int n = routes.size();
    unordered_map<int, vector<int>> map;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < routes[i].size(); ++j) {
            int busStopNo = routes[i][j];
            map[busStopNo].push_back(i);
        }
    }

    queue<int> q;
    unordered_set<int> busStopVisited;
    unordered_set<int> busVisited;
    int level = 0;
    q.push(S);
    busStopVisited.insert(S);

    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            int currentStop = q.front();
            q.pop();
            if (currentStop == T) {
                return level;
            }

            if (map.find(currentStop) != map.end()) {
                vector<int>& buses = map[currentStop];
                for (int bus : buses) {
                    if (busVisited.count(bus) > 0) {
                        continue;
                    }

                    vector<int>& busRoute = routes[bus];
                    for (int nextStop : busRoute) {
                        if (busStopVisited.count(nextStop) > 0) {
                            continue;
                        }

                        q.push(nextStop);
                        busStopVisited.insert(nextStop);
                    }
                    busVisited.insert(bus);
                }
            }
        }
        ++level;
    }
    return -1; // If destination is not reachable
}

int main() {
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7}
    };
    int src = 1; // source bus stop
    int dest = 6; // destination bus stop

    cout << numBusesToDestination(routes, src, dest) << endl;
    return 0;
}
