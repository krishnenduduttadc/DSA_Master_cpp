#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the dimensions of the matrix

    vector < vector < int >> mat(n, vector < int > (m)); // Create a 2D vector to store the matrix

    // Read the elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}

/*
3 3
3 1 5
8 2 1
4 6 0

*/