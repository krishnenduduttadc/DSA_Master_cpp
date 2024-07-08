#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int row;
    int col;
    Pair(int r, int c) : row(r), col(c) {}
};

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<Pair> q;

    // Enqueue all land cells initially
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                q.push(Pair(i, j));
            }
        }
    }

    if (q.empty() || q.size() == n * n) {
        return -1; // If there are no water cells or all are land
    }

    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int level = -1;

    while (!q.empty()) {
        ++level;
        int size = q.size();

        while (size-- > 0) {
            Pair current = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int row_dash = current.row + dirs[i][0];
                int col_dash = current.col + dirs[i][1];

                if (row_dash < 0 || col_dash < 0 || row_dash >= n || col_dash >= n ||
                    grid[row_dash][col_dash] == 1) {
                    continue; // Skip if out of bounds or cell is land
                }

                q.push(Pair(row_dash, col_dash));
                grid[row_dash][col_dash] = 1; // Mark as visited
            }
        }
    }

    return level;
}

int main() {
    // Hardcoded input values
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 1}
    };

    cout << maxDistance(grid) << endl;

    return 0;
}
