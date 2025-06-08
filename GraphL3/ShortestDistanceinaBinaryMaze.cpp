#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int,int> source, pair<int,int> destination) {
    if (source == destination) return 0;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    queue<pair<int, pair<int,int>>> q;
    q.push({0, source});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (int i = 0; i < 4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m
                && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {

                dist[newr][newc] = dis + 1;

                if (make_pair(newr, newc) == destination) {
                    return dist[newr][newc];
                }

                q.push({dist[newr][newc], {newr, newc}});
            }
        }
    }

    return -1; // destination not reachable
}

int main() {
    pair<int,int> source = {0,1};
    pair<int,int> destination = {2,2};

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 0, 1}
    };

    int res = shortestPath(grid, source, destination);

    cout << res << "\n";

    return 0;
}
