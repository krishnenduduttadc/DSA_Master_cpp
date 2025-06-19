#include <iostream>
using namespace std;

int main() {
    int n = 2; // Number of rows
    int m = 4; // Number of columns

    int arr[n][m] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24}
    };

    // Print the array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
