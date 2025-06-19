#include <iostream>
using namespace std;

int main() {
    int n = 4; 
    int arr[4][4] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34},
        {41, 42, 43, 44}
    };

    // Print array elements in Wakanda-1 zigzag pattern
    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            // Print top to bottom for even-indexed columns
            for (int i = 0; i < n; ++i) {
                cout << arr[i][j] << endl;
            }
        } else {
            // Print bottom to top for odd-indexed columns
            for (int i = n - 1; i >= 0; --i) {
                cout << arr[i][j] << endl;
            }
        }
    }

    return 0;
}
