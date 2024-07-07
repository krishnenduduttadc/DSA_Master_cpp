#include <iostream>
#include <vector>

using namespace std;

int binsearch(const vector<int>& arr, int low, int high, int x) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
        return mid;
    } else if (arr[mid] > x) {
        return binsearch(arr, low, mid - 1, x);
    } else {
        return binsearch(arr, mid + 1, high, x);
    }
}

int main() {
    vector<int> arr = {3, 5, 7, 8, 9, 11, 45, 76};
    int result = binsearch(arr, 0, arr.size() - 1, 11);
    cout << result << endl;
    return 0;
}
