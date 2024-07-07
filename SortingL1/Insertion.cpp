#include <iostream>
using namespace std;

class InsertionSort {
public:
    // Function to perform insertion sort on array arr of size n
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            insert(arr, i);
        }
    }

private:
    // Helper function to insert arr[i] into the sorted sub-array arr[0...i-1]
    void insert(int arr[], int i) {
        int key = arr[i]; // Element to be inserted
        int j = i - 1;    // Start comparing with the previous element

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place key at its correct position
    }
};

int main() {
    InsertionSort solution;

    // Hardcoded input array
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array using insertion sort
    solution.insertionSort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
