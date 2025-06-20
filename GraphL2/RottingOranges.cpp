#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for pair

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 2) {
                q.push(make_pair(i, j));
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) return 0;

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int minutes = -1;

    while (!q.empty()) {
        int size = q.size();
        minutes++;

        while (size-- > 0) {
            pair<int, int> front = q.front();
            q.pop();

            int row = front.first;
            int col = front.second;

            for (int d = 0; d < 4; ++d) {
                int r = row + dirs[d][0];
                int c = col + dirs[d][1];

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2; // Rot the fresh orange
                    q.push(make_pair(r, c));
                    fresh--;
                }
            }
        }
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << orangesRotting(grid) << endl;

    return 0;
}
