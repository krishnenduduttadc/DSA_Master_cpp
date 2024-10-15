#include <bits/stdc++.h>

using namespace std;

// Function to rotate the matrix 90 degrees clockwise in-place
void rotateMatrix(vector<vector<int>>& matrix, int N) {
    // Step 1: Transpose the matrix (swap elements across the diagonal)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row to achieve 90-degree clockwise rotation
    for (int i = 0; i < N; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int N;
    cin >> N;

    // Reading the NxN matrix
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Rotate the matrix 90 degrees clockwise in-place
    rotateMatrix(matrix, N);

    // Output the rotated matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


/*
3
3 1 5
8 2 1
4 6 0
*/