#include <bits/stdc++.h>
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
    // Hardcoded dimensions and target value
    int N = 3; // Number of rows
    int M = 4; // Number of columns
    int X = 7; // Target value to search for

    // Hardcoded matrix elements
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Search for the element and output the result
    if (searchInMatrix(matrix, N, M, X)) {
        cout << "YES" << endl; // Element exists
    } else {
        cout << "NO" << endl; // Element does not exist
    }

    return 0;
}
