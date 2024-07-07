#include <iostream>
#include <vector>

using namespace std;

int searchFirst(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            high = mid - 1;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            if (mid == 0 || arr[mid - 1] != arr[mid]) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int searchLast(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            if (mid == arr.size() - 1 || arr[mid] != arr[mid + 1]) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int countOccurrences(const vector<int>& arr, int x) {
    int first = searchFirst(arr, x);
    if (first == -1) {
        return 0;
    } else {
        return searchLast(arr, x) - first + 1;
    }
}

int main() {
    vector<int> arr = {3, 7, 7, 7, 9};
    cout << countOccurrences(arr, 7) << endl;
    return 0;
}
