#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // Read the number of rows and columns

    vector<vector<int>> matrix(N, vector<int>(M)); // Define a 2D vector to store the matrix

    // Read the elements of the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<bool> zeroRows(N, false);
    vector<bool> zeroCols(M, false);

    // First pass to find zero rows and columns
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Set rows to zero
    for (int i = 0; i < N; i++) {
        if (zeroRows[i]) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set columns to zero
    for (int j = 0; j < M; j++) {
        if (zeroCols[j]) {
            for (int i = 0; i < N; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Output the modified matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
3 3
4 6 0
8 2 1
3 1 5

*/