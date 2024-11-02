#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>>& matrix, int N, int M) {
    vector<vector<int>> dp(N, vector<int>(M, 0));
    
    dp[0][0] = matrix[0][0];

    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j];
    }

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

    return dp[N - 1][M - 1];
}

int main() {
    int N = 3, M = 3;

    vector<vector<int>> matrix = {
        {4, 3, 0},
        {8, 2, 1},
        {3, 1, 5}
    };

    cout << minPathSum(matrix, N, M) << endl;

    return 0;
}
