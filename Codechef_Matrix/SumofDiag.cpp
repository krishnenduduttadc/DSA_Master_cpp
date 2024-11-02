#include <bits/stdc++.h>

using namespace std;

int main() {
    // Hardcoded size of the matrix
    int n = 3; // Size of the matrix (3x3)
    
    // Hardcoded matrix elements
    int arr[3][3] = {
        {3, 1, 5},
        {8, 2, 1},
        {4, 6, 0}
    };
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the element is on the main diagonal
            if (i == j) {
                sum += arr[i][j];
            }
            // Check if the element is on the secondary diagonal
            else if (i + j == n - 1) {
                sum += arr[i][j];
            }
        }
    }
    
    cout << sum << endl; // Output the sum

    return 0;
}
