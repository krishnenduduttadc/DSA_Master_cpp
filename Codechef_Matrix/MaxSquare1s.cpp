#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquareArea(vector<vector<int>>& matrix, int N) {
    // DP table to store the size of the largest square ending at each cell
    vector<vector<int>> dp(N, vector<int>(N, 0));
    int maxSide = 0;  // To track the largest square's side length

    // Fill the DP table
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    // If we're in the first row or first column, the largest square is 1x1
                    dp[i][j] = 1;
                } else {
                    // The size of the square ending at (i, j) is determined by its neighbors
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                // Update the maximum side length
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    // The area of the largest square is the square of its side length
    return maxSide * maxSide;
}

int main() {
    int N;
    cin >> N;  // Read the size of the matrix

    vector<vector<int>> matrix(N, vector<int>(N));  // Initialize the matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Output the area of the maximal square submatrix with all 1's
    cout << maximalSquareArea(matrix, N) << endl;

    return 0;
}



/*
3
0 1 0
0 1 1
0 1 1
*/