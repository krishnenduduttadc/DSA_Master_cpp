#include <iostream>
using namespace std;

// Insertion sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Store the current element as key
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the key at its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    
    // Taking array size input
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Taking array elements input
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling the insertion sort function
    insertionSort(arr, n);

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