#include <bits/stdc++.h>

using namespace std;

// Function to rotate the matrix 90 degrees clockwise in-place
void rotateMatrix(vector<vector<int>>& matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < N; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int N = 3;

    vector<vector<int>> matrix = {
        {3, 1, 5},
        {8, 2, 1},
        {4, 6, 0}
    };

    rotateMatrix(matrix, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
