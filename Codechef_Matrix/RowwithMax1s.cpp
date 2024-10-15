#include <bits/stdc++.h>
using namespace std;

int findRowWithMaxOnes(vector<vector<int>>& mat, int n, int m) {
    int maxRowIndex = -1;  // To store the index of the row with max 1s
    int j = m - 1;         // Start from the top-right corner of the matrix

    // Traverse each row
    for (int i = 0; i < n; i++) {
        // Move left while we encounter 1's
        while (j >= 0 && mat[i][j] == 1) {
            maxRowIndex = i;  // Update the row index
            j--;              // Move left
        }
    }

    return maxRowIndex;
}

int main() {
    int n, m;
    cin >> n >> m;  // Read the number of rows and columns

    vector<vector<int>> mat(n, vector<int>(m));  // Initialize a 2D vector (matrix)

    // Read the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    // Find the row with the maximum number of 1's
    int result = findRowWithMaxOnes(mat, n, m);

    // Output the result (correcting for 1-based index)
    if (result != -1) {
        cout << result + 1 << endl;  // Adjust for 1-based index
    } else {
        cout << "No 1s in the matrix" << endl;  // Handle the case with no 1s
    }

    return 0;
}

/*
3 3
0 1 1
0 1 1
0 1 1

*/