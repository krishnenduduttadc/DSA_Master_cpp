#include <iostream>
using namespace std;

void findFirstAndLastIndex(int arr[], int n, int d) {
    int low = 0;
    int high = n - 1;
    int firstIndex = -1;
    int lastIndex = -1;

    // Finding the first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (d > arr[mid]) {
            low = mid + 1;
        } else if (d < arr[mid]) {
            high = mid - 1;
        } else {
            firstIndex = mid;
            high = mid - 1;
        }
    }

    // Finding the last occurrence
    low = 0;
    high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (d > arr[mid]) {
            low = mid + 1;
        } else if (d < arr[mid]) {
            high = mid - 1;
        } else {
            lastIndex = mid;
            low = mid + 1;
        }
    }

    cout << "First Index: " << firstIndex << endl;
    cout << "Last Index: " << lastIndex << endl;
}

int main() {
    int arr[] = {1, 5, 10, 15, 22, 33, 33, 33, 33, 33, 40, 42, 55, 66, 77, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 33;

    findFirstAndLastIndex(arr, n, d);

    return 0;
}
