#include <iostream>
using namespace std;

// Helper function to insert arr[i] into the sorted subarray arr[0...i-1]
void insert(int arr[], int i) {
    int key = arr[i];
    int j = i - 1;

    // Shift elements that are greater than key to one position ahead
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

// Function to perform insertion sort on the array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        insert(arr, i);
    }
}

int main() {
    // Hardcoded input array
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array
    insertionSort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
