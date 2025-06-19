#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum path sum for grid1: " << minPathSum(grid1) << endl;

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Minimum path sum for grid2: " << minPathSum(grid2) << endl;

    vector<vector<int>> grid3 = {
        {1, 2},
        {1, 1}
    };
    cout << "Minimum path sum for grid3: " << minPathSum(grid3) << endl;

    return 0;
}
