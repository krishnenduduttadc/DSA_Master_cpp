#include <iostream>
using namespace std;

void reverse(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;
        low++;
        high--;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, n);
    return 0;
}
