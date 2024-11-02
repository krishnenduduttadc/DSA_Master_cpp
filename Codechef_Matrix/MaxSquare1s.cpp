#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquareArea(vector<vector<int>>& matrix, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    int maxSide = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide;
}

int main() {
    int N = 3;

    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 1, 1},
        {0, 1, 1}
    };

    cout << maximalSquareArea(matrix, N) << endl;

    return 0;
}
