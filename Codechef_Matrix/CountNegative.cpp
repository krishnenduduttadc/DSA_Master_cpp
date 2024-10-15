#include <bits/stdc++.h>
using namespace std;


int countNegatives(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int row_index = 0;
    int col_index = cols - 1;
    int negatives_count = 0;
    while (row_index < rows) {
        while (col_index >= 0 && matrix[row_index][col_index] < 0)
            --col_index;
        negatives_count += cols - col_index - 1;
        ++row_index;
    }
    return negatives_count;
}


int main() {
	 int n, m;
    cin >> n >> m; // Reading the dimensions of the matrix
    
    vector<vector<int>> mat(n, vector<int>(m)); // Initializing a 2D vector to store the matrix
    
    // Loop to read the matrix elements
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j]; // Reading each element into the matrix
        }
    }
    
    cout << countNegatives(mat);

}


/*
3 4
8 7 6 -1
7 7 -1 -2
4 -5 -6 -7

*/