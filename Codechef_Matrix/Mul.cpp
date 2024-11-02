#include <bits/stdc++.h>

using namespace std;

int main() {
    int m = 2, n = 3, p = 2;

    int a[2][3] = {
        {2, 3, 4},
        {4, 5, 6}
    };

    int b[3][2] = {
        {1, 2},
        {3, 4},
        {2, 2}
    };
    
    int result[m][p];

    // Initialize result matrix to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Output the resultant matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
