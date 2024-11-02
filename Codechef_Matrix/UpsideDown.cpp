#include <bits/stdc++.h>

using namespace std;

int main() {
    // Hardcoded dimensions of the matrix
    int n = 3; // Number of rows
    int m = 3; // Number of columns

    // Hardcoded matrix elements
    vector<vector<int>> mat = {
        {3, 1, 5},
        {8, 2, 1},
        {4, 6, 0}
    };

    // Output the matrix in reverse order (bottom to top)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
