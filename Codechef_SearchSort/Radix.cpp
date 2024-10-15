#include <iostream>
#include <vector>
#include <algorithm>  // For max_element
using namespace std;

// Function to get the maximum value in the array
int getMax(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Counting Sort function to sort based on a specific digit (exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};  // Since we're dealing with digits (0-9), we use a fixed array of size 10

    // Count the occurrences of each digit in the given place (exp)
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    // Compute cumulative count to determine positions
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to determine the number of digits
    int max_val = getMax(arr);

    // Perform counting sort for every digit. exp is 10^i (i.e., 1, 10, 100, ...)
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    int n;

    // Taking input for the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);  // Declare vector of size n

    // Taking input for the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call radixSort to sort the array
    radixSort(arr);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


/*
8
6 5 3 1 8 7 2 4
*/