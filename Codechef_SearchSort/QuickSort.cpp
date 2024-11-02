#include <iostream>
#include <vector>
using namespace std;

// Function to swap elements
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition function for quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot is chosen as the last element
    int i = low - 1;  // Index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);  // Swap elements if current is smaller than pivot
        }
    }
    swap(arr, i + 1, high);  // Move pivot to the correct position
    return i + 1;  // Return the partition index
}

// QuickSort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition the array

        quickSort(arr, low, pi - 1);  // Sort the elements before partition
        quickSort(arr, pi + 1, high);  // Sort the elements after partition
    }
}

int main() {
    int n = 8; // Hardcoded number of elements

    vector<int> arr = {6, 5, 3, 1, 8, 7, 2, 4};  // Hardcoded array elements

    // Call quickSort to sort the array
    quickSort(arr, 0, n - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
