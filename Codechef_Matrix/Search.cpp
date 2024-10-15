#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

bool searchInMatrix(vector<vector<int>>& matrix, int N, int M, int X) {
    int left = 0, right = N * M - 1; // Define the binary search range

    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle index
        int midValue = matrix[mid / M][mid % M]; // Convert mid index to 2D coordinates

        if (midValue == X) {
            return true; // Found the target
        } else if (midValue < X) {
            left = mid + 1; // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }

    return false; // Target not found
}

int main() {
    int N, M, X;
    cin >> N >> M >> X; // Read dimensions and target value

    vector<vector<int>> matrix(N, vector<int>(M)); // Initialize the matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Search for the element and output the result
    if (searchInMatrix(matrix, N, M, X)) {
        cout << "YES" << endl; // Element exists
    } else {
        cout << "NO" << endl; // Element does not exist
    }

    return 0;
}



/*
3 4 7
1 2 3 4
5 6 7 8
9 10 11 12

*/