#include <iostream>
using namespace std;

void transpose(int arr[][3], int n) {
    // Swap elements across the diagonal
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = sizeof(arr) / sizeof(arr[0]); // Number of rows/columns

    transpose(arr, n);

    return 0;
}
