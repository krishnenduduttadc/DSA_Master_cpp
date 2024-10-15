#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>>& matrix, int N, int M) {
    int top = 0, bottom = N - 1, left = 0, right = M - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Traverse from right to left across the bottom row (if there are remaining rows)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Traverse from bottom to top along the left column (if there are remaining columns)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;  // Read the dimensions of the matrix

    vector<vector<int>> matrix(N, vector<int>(M));  // Initialize the matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Print the matrix in spiral fashion
    printSpiral(matrix, N, M);

    return 0;
}


/*
3 4
1 2 3 4
5 6 7 8
9 10 11 12

*/