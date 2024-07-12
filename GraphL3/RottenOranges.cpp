#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Structure to store (row, column) coordinates and time at which the orange rots.
    struct Pair {
        int row, col, tm;
        Pair(int r, int c, int t) : row(r), col(c), tm(t) {}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<Pair> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0;

        // Initialize the queue with all rotting oranges and count fresh oranges.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push(Pair(i, j, 0));
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    ++cntFresh;
                }
            }
        }

        int tm = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int cnt = 0;

        // Perform BFS to compute the minimum time to rot all oranges.
        while (!q.empty()) {
            int r = q.front().row;
            int c = q.front().col;
            int t = q.front().tm;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push(Pair(nrow, ncol, t + 1));
                    vis[nrow][ncol] = 2;
                    ++cnt;
                }
            }
        }

        // If not all fresh oranges are rottened, return -1.
        if (cnt != cntFresh) return -1;
        return tm;
    }
};

int main() {
    vector<vector<int>> grid = {{0,1,2},{0,1,2},{2,1,1}};
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans << endl;
    return 0;
}
