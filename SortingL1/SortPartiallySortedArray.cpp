#include <iostream>
#include <vector>
using namespace std;

// Function to insert the last unsorted element into its correct position
void insertElement(vector<int>& arr) {
    int n = arr.size();
    for (int j = n - 2; j >= 0; j--) {
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        } else {
            break;
        }
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Hardcoded input array
    vector<int> arr = {3, 1, 4, 1, 5}; // Example input

    // Insert last unsorted element into correct position
    insertElement(arr);

    // Print the updated array
    printArray(arr);

    return 0;
}
