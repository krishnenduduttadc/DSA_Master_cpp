#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<pair<int,int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int fresh = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int time = 0, rotten = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        int r = front.first.first;
        int c = front.first.second;
        int t = front.second;

        time = max(time, t);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                q.push({{nr, nc}, t + 1});
                vis[nr][nc] = 2;
                rotten++;
            }
        }
    }

    return (rotten == fresh) ? time : -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}
    };

    int ans = orangesRotting(grid);
    cout << "Answer = " << ans << endl;

    return 0;
}
