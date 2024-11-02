#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Function to sort the matrix diagonally
void diagonalSort(vector<vector<int>>& matrix, int N, int M) {
    // Map to store elements of each diagonal, where the key is (i - j)
    map<int, vector<int>> diagonals;

    // Collect all elements of each diagonal
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            diagonals[i - j].push_back(matrix[i][j]);
        }
    }

    // Sort each diagonal
    for (auto& diag : diagonals) {
        sort(diag.second.begin(), diag.second.end());
    }

    // Place the sorted elements back into the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = diagonals[i - j].front();
            diagonals[i - j].erase(diagonals[i - j].begin());
        }
    }
}

int main() {
    // Hardcoded dimensions
    int N = 3; // Number of rows
    int M = 3; // Number of columns

    // Hardcoded matrix elements
    vector<vector<int>> matrix = {
        {3, 1, 5},
        {8, 2, 1},
        {4, 6, 0}
    };

    // Sort the matrix diagonally
    diagonalSort(matrix, N, M);

    // Output the diagonally sorted matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
