#include <iostream>
#include <vector>

using namespace std;

int searchR(const vector<int>& arr, int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] > x) {
        return searchR(arr, low, mid - 1, x);
    } else if (arr[mid] < x) {
        return searchR(arr, mid + 1, high, x);
    } else {
        if (mid == 0 || arr[mid - 1] != arr[mid]) {
            return mid;
        } else {
            return searchR(arr, low, mid - 1, x);
        }
    }
}

int searchI(const vector<int>& arr, int x) {
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

int main() {
    vector<int> arr = {3, 5, 8, 8, 9, 9};
    cout << searchR(arr, 0, arr.size() - 1, 8) << endl;
    cout << searchI(arr, 8) << endl;
    return 0;
}
