#include <iostream>
using namespace std;

int medianOfThree(int arr[], int l, int h) {
    int mid = l + (h - l) / 2;
    if (arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    if (arr[l] > arr[h]) swap(arr[l], arr[h]);
    if (arr[mid] > arr[h]) swap(arr[mid], arr[h]);
    return mid;
}

int partition(int arr[], int l, int h) {
    int medianIndex = medianOfThree(arr, l, h);
    swap(arr[l], arr[medianIndex]);  // Move median to start as pivot

    int pivot = arr[l];
    int left = l + 1;
    int right = h;

    while (left <= right) {
        while (left <= right && arr[left] < pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left <= right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    swap(arr[l], arr[right]);  // Put pivot in correct place
    return right;
}

void rquicksort(int arr[], int l, int h) {
    if (l < h) {
        int pivot = partition(arr, l, h);
        rquicksort(arr, l, pivot - 1);
        rquicksort(arr, pivot + 1, h);
    }
}

int main() {
    int arr[] = {24, 97, 40, 67, 88, 85, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    rquicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
