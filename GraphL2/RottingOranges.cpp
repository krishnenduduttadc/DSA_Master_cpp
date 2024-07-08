#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Pair {
public:
    int row;
    int col;

    Pair(int r, int c) : row(r), col(c) {}
};

int orangesRotting(vector<vector<int>>& grid) {
    queue<Pair> q;
    int fresh = 0;

    // Initialize the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 2) {
                q.push(Pair(i, j));
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0) {
        return 0;
    }

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int level = -1;

    // BFS to rot the adjacent fresh oranges
    while (!q.empty()) {
        int size = q.size();
        level++;
        while (size--) {
            Pair rem = q.front();
            q.pop();
            for (const auto& dir : dirs) {
                int rdash = rem.row + dir[0];
                int cdash = rem.col + dir[1];

                if (rdash >= 0 && cdash >= 0 && rdash < grid.size() && cdash < grid[0].size() && grid[rdash][cdash] == 1) {
                    q.push(Pair(rdash, cdash));
                    grid[rdash][cdash] = 0; // Mark the orange as processed
                    fresh--;
                }
            }
        }
    }

    return fresh == 0 ? level : -1;
}

int main() {
    // Hardcoded input
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << orangesRotting(grid) << endl;

    return 0;
}
