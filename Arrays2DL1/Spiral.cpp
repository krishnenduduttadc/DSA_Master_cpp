#include <iostream>
using namespace std;

void printSpiral(int arr[][5], int n, int m) {
    int minr = 0, minc = 0;
    int maxr = n - 1, maxc = m - 1;
    int tne = n * m; // Total number of elements
    int cnt = 0;

    while (cnt < tne) {
        // Print from left to right in the current row
        for (int i = minr, j = minc; i <= maxr && cnt < tne; ++i) {
            cout << arr[i][j] << " ";
            ++cnt;
        }
        ++minc;

        // Print from top to bottom in the current column
        for (int i = maxr, j = minc; j <= maxc && cnt < tne; ++j) {
            cout << arr[i][j] << " ";
            ++cnt;
        }
        --maxr;

        // Print from right to left in the current row (if any)
        for (int i = maxr, j = maxc; i >= minr && cnt < tne; --i) {
            cout << arr[i][j] << " ";
            ++cnt;
        }
        --maxc;

        // Print from bottom to top in the current column (if any)
        for (int i = minr, j = maxc; j >= minc && cnt < tne; --j) {
            cout << arr[i][j] << " ";
            ++cnt;
        }
        ++minr;
    }
}

int main() {
    int n = 3; // Number of rows
    int m = 5; // Number of columns
    int arr[3][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35}
    };

    printSpiral(arr, n, m);

    return 0;
}
