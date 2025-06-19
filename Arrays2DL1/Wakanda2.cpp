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

    // Print array elements in diagonal order
    for (int g = 0; g < n; ++g) {
        for (int i = 0, j = g; j < n; ++i, ++j) {
            cout << arr[i][j] << endl;
        }
    }

    return 0;
}
