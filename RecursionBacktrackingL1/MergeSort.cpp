#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int temp[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    int x = 0;
    for (int m = start; m <= end; m++) {
        arr[m] = temp[x++];
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

int main() {
    int arr[] = {5, 6, 4, 3, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
