#include <iostream>
using namespace std;

int countSubsets(int arr[], int n, int i, int X) {
    if (i == n) {
        if (X == 0) {
            return 1;
        }
        return 0;
    }

    int inclu = countSubsets(arr, n, i + 1, X - arr[i]);
    int exclu = countSubsets(arr, n, i + 1, X);
    return inclu + exclu;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int X = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSubsets(arr, n, 0, X) << endl;

    return 0;
}
