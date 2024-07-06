#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class NoofEnclaves {
private:
    struct Pair {
        int first;
        int second;

        Pair(int f, int s) : first(f), second(s) {}
    };

public:
    static int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<Pair> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse boundary elements
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // First row, first col, last row, last col
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    // If it is land, store it in the queue
                    if (grid[i][j] == 1) {
                        q.push(Pair(i, j));
                        vis[i][j] = 1;
                    }
                }
            }
        }

        static const int delrow[] = {-1, 0, 1, 0};
        static const int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all 4 directions
            for (int i = 0; i < 4; ++i) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check for valid coordinates and for land cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push(Pair(nrow, ncol));
                    vis[nrow][ncol] = 1;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Check for unvisited land cell
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    ++cnt;
            }
        }

        return cnt;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int ans = NoofEnclaves::numberOfEnclaves(grid);
    cout << ans << endl;

    return 0;
}
