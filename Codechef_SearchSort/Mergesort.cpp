#include <iostream>
#include <vector>
using namespace std;

// Merge function to combine two sorted halves
void merge(vector<int> &arr, int left, int middle, int right) {
    vector<int> a, b;

    // Copy left half to a
    for (int i = left; i <= middle; i++) {
        a.push_back(arr[i]);
    }

    // Copy right half to b
    for (int i = middle + 1; i <= right; i++) {
        b.push_back(arr[i]);
    }

    int i = 0, j = 0;
    vector<int> res;

    // Merge the two halves back into res
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    // Add remaining elements from a
    while (i < a.size()) {
        res.push_back(a[i]);
        i++;
    }

    // Add remaining elements from b
    while (j < b.size()) {
        res.push_back(b[j]);
        j++;
    }

    // Copy the sorted result back into the original array
    for (int k = 0; k < res.size(); k++) {
        arr[left + k] = res[k];
    }
}

// MergeSort function to recursively divide and sort the array
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);       // Sort the left half
        mergeSort(arr, mid + 1, right);  // Sort the right half
        merge(arr, left, mid, right);    // Merge the sorted halves
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

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

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