#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge temp arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Given array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
