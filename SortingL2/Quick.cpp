#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        // Move the left pointer to the right until an element larger than the pivot is found
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        // Move the right pointer to the left until an element smaller than the pivot is found
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        // If left is still to the left of right, swap the elements at left and right
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Place the pivot in the correct position
    swap(arr[low], arr[right]);

    return right; // Return the final position of the pivot
}

int main() {
    int arr[] = {9, 3, 4, 8, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int low = 0;
    int high = n - 1;

    int pivotIndex = partition(arr, low, high);

    cout << "Pivot is at index: " << pivotIndex << endl;
    cout << "Array after partitioning: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
