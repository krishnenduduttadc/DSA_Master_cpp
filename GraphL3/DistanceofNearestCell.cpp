#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// NodeT class to represent coordinates and steps in BFS
class NodeT {
public:
    int first;
    int second;
    int third;

    NodeT(int _first, int _second, int _third) {
        this->first = _first;
        this->second = _second;
        this->third = _third;
    }
};

class DistanceofNearestCell {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Visited and distance matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        // Queue for BFS
        queue<NodeT> q;

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start BFS from cells containing 1
                if (grid[i][j] == 1) {
                    q.push(NodeT(i, j, 0));
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        // Directions arrays for moving in 4 directions (up, right, down, left)
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int steps = q.front().third;
            q.pop();

            dist[row][col] = steps;

            // Check all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check for valid unvisited cell
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push(NodeT(nrow, ncol, steps + 1));
                }
            }
        }

        // Return distance matrix
        return dist;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    DistanceofNearestCell obj;
    vector<vector<int>> ans = obj.nearest(grid);

    // Printing the result
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
