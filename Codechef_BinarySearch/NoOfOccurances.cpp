#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(const int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return (arr[left] == target) ? left : -1;
}

int lastOccurrence(const int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left < right) {
        int middle = left + (right - left + 1) / 2;
        if (arr[middle] <= target) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }
    return (arr[left] == target) ? left : -1;
}

int countOccurrences(const int arr[], int n, int target) {
    int first = firstOccurrence(arr, n, target);
    if (first == -1) {
        return 0;
    }
    int last = lastOccurrence(arr, n, target);
    return last - first + 1;
}

int main() {
    int n = 8;
    int arr[] = {1, 2, 3, 5, 5, 5, 7, 8};
    int target = 5;

    cout << countOccurrences(arr, n, target) << endl;
    return 0;
}
