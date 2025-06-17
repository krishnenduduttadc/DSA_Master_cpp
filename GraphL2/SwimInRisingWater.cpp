#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int swimInRisingWater(vector<vector<int>>& grid) {
    int n = grid.size();

    // Min-heap priority queue storing (msf, row, col)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push(make_tuple(grid[0][0], 0, 0));  // msf, row, col

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!pq.empty()) {
        int msf, row, col;
        tie(msf, row, col) = pq.top();
        pq.pop();

        if (row == n - 1 && col == n - 1) {
            return msf;
        }

        if (vis[row][col]) continue;
        vis[row][col] = true;

        for (int i = 0; i < 4; ++i) {
            int r = row + dirs[i][0];
            int c = col + dirs[i][1];

            if (r >= 0 && c >= 0 && r < n && c < n && !vis[r][c]) {
                pq.push(make_tuple(max(msf, grid[r][c]), r, c));
            }
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    cout << swimInRisingWater(grid) << endl;
    return 0;
}
