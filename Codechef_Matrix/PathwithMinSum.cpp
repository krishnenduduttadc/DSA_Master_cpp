#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>>& matrix, int N, int M) {
    // Create a DP table
    vector<vector<int>> dp(N, vector<int>(M, 0));
    
    // Initialize the first cell (top-left corner)
    dp[0][0] = matrix[0][0];

    // Fill the first row (can only come from the left)
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    // Fill the first column (can only come from above)
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    // Fill the rest of the DP table
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

    // The answer is in the bottom-right corner
    return dp[N - 1][M - 1];
}

int main() {
    int N, M;
    cin >> N >> M;  // Read the dimensions of the matrix

    vector<vector<int>> matrix(N, vector<int>(M));  // Initialize the matrix

    // Read the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Output the minimum sum of path cells from top-left to bottom-right
    cout << minPathSum(matrix, N, M) << endl;

    return 0;
}


/*
3 3
4 3 0
8 2 1
3 1 5

*/