#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, p;

    // Input for first matrix
    cin >> m >> n;
    int a[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Input for second matrix
    cin >> n >> p; // Note: n is read again to ensure matrix dimensions match
    int b[n][p];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> b[i][j];
        }
    }
    
    
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
            for (int k = 0; k < n; k++) { // Note: 'k' runs over the common dimension n
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


}

/*
2 3
2 3 4
4 5 6
3 2
1 2
3 4
2 2

*/