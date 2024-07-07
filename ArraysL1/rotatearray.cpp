#include <iostream>
using namespace std;

void rotate(int arr[], int d, int n) {
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }

    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 6, 2, 5, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, 5, n);
    return 0;
}
