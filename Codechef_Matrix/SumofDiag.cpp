#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the matrix
    int arr[n][n]; // Declare a 2D array to store the matrix elements

    // Loop to read matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j]; // Read each element of the matrix
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sum += arr[i][j];
            }
            else if (i + j == n-1) {
                sum += arr[i][j];
            }
        }
    }
    cout << sum << endl;

    

    
}


/*
3
3 1 5
8 2 1
4 6 0
*/