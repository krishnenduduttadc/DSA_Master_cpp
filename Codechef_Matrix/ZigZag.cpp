#include <bits/stdc++.h>

using namespace std;

int main() {
    // Hardcoded dimensions of the matrix
    int n = 3; // Number of rows
    int m = 3; // Number of columns

    // Hardcoded matrix elements
    int arr[3][3] = {
        {4, 6, 0},
        {8, 2, 1},
        {3, 1, 5}
    };

    bool dirl = true; // Direction toggle
    for (int i = 0; i < n; i++) { // Loop through rows
        for (int j = 0; j < m; j++) { // Loop through columns
            if (dirl) {
                cout << arr[i][j] << " "; // Print in left to right direction
            } else {
                cout << arr[i][m - j - 1] << " "; // Print in right to left direction
            }
        }
        dirl = !dirl; // Toggle the direction for the next row
    }

    return 0;
}
