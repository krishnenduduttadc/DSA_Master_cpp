#include <iostream>
#include <vector>
using namespace std;

int largestSquareSubmatrix(vector<vector<int>>& arr) {
    int rows = arr.size();
    if (rows == 0) return 0;
    int cols = arr[0].size();
    if (cols == 0) return 0;
    
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int largestSide = 0;

    // Fill the dp array
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i == rows - 1 || j == cols - 1) {
                dp[i][j] = arr[i][j];
            } else {
                if (arr[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    int minSide = min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
                    dp[i][j] = minSide + 1;
                }
            }
            if (dp[i][j] > largestSide) {
                largestSide = dp[i][j];
            }
        }
    }

    return largestSide; // Return the side length of the largest square submatrix
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1}
    };

    cout << largestSquareSubmatrix(arr) << endl;

    return 0;
}
