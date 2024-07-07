#include <iostream>
#include <vector>

using namespace std;

int binsearchlast(const vector<int>& arr, int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] > x) {
        return binsearchlast(arr, low, mid - 1, x);
    } else if (arr[mid] < x) {
        return binsearchlast(arr, mid + 1, high, x);
    } else {
        if (mid == arr.size() - 1 || arr[mid] != arr[mid + 1]) {
            return mid;
        } else {
            return binsearchlast(arr, mid + 1, high, x);
        }
    }
}

int main() {
    vector<int> arr = {3, 5, 7, 8, 9, 11, 11, 11};
    cout << binsearchlast(arr, 0, arr.size() - 1, 11) << endl;
    return 0;
}
