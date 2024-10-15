#include <iostream>
using namespace std;

// Selection sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        // Find the minimum element in the unsorted portion of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
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

    // Calling the selection sort function
    selectionSort(arr, n);

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