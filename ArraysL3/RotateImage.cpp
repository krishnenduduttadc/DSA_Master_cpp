#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < m; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
        int sp = 0;
        int ep = m - 1;

        while (sp < ep) {
            swap(matrix[i][sp], matrix[i][ep]);
            sp++;
            ep--;
        }
    }
}

// Function to print the 2D matrix
void print2DArray(const vector<vector<int>>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        for (size_t j = 0; j < array[i].size(); j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    print2DArray(matrix);

    rotate(matrix);

    cout << "Rotated matrix:" << endl;
    print2DArray(matrix);

    return 0;
}
