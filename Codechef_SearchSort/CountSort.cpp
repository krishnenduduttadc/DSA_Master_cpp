#include <iostream>
#include <vector>
#include <algorithm>  // For max_element
using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;  // Edge case: If the array is empty, there's nothing to sort

    // Find the maximum value in the array
    int max_val = *max_element(arr.begin(), arr.end());
    
    // Create a count array to store the frequency of each value
    vector<int> count(max_val + 1, 0);

    // Count the occurrences of each value in the array
    for (int num : arr) {
        count[num]++;
    }

    // Reconstruct the sorted array using the count array
    int sorted_index = 0;
    for (int i = 0; i <= max_val; ++i) {
        while (count[i] > 0) {
            arr[sorted_index++] = i;
            count[i]--;
        }
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

    // Call countingSort to sort the array
    countingSort(arr);

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