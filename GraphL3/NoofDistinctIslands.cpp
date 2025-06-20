#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pair {
    int first;
    int second;

    Pair(int f, int s) {
        first = f;
        second = s;
    }
};

void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    static const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    visited[i][j] = true;
    queue<Pair> q;
    q.push(Pair(i, j));

    while (!q.empty()) {
        int first = q.front().first;
        int second = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int row = first + directions[d][0];
            int col = second + directions[d][1];
            if (row >= 0 && row < grid.size() &&
                col >= 0 && col < grid[0].size() &&
                !visited[row][col] && grid[row][col] == '1') {
                visited[row][col] = true;
                q.push(Pair(row, col));
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j] && grid[i][j] == '1') {
                ++count;
                bfs(i, j, grid, visited);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '1'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int numberOfIslands = numIslands(grid);
    cout << "Number of distinct islands: " << numberOfIslands << endl;

    return 0;
}
