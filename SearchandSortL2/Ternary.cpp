#include <iostream>
using namespace std;

int ternarySearch(int arr[], int left, int right, int key) {
    if (right >= left) {
        // Calculate the two mid points
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check if the key is present at any of the mids
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        // If key is smaller than mid1, search in the left third
        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        }
        // If key is larger than mid2, search in the right third
        else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        }
        // If key is between mid1 and mid2, search in the middle third
        else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    // Key not found in array
    return -1;
}

int main() {
    int n, key, result;

    // Taking input for the array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; // Declaring the array

    // Taking input for the sorted array elements
    cout << "Enter the sorted elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Taking input for the element to be searched
    cout << "Enter the element to search: ";
    cin >> key;

    // Performing ternary search
    result = ternarySearch(arr, 0, n - 1, key);

    // Displaying the result
    if (result == -1) {
        cout << "Element not found in the array.\n";
    } else {
        cout << "Element found at index " << result << ".\n";
    }

    return 0;
}
