#include <iostream>
#include <vector>
using namespace std;

int findRotationCount(vector<int>& arr) {
    int lo = 0;
    int hi = arr.size() - 1;

    if (arr[lo] <= arr[hi]) {
        return 0;
    }

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (mid < hi && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }
        else if (mid > lo && arr[mid] < arr[mid - 1]) {
            return mid;
        }
        else if (arr[lo] <= arr[mid]) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    return 0; // Should not reach here in a rotated sorted array scenario
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 8, 0, 1, 2};

    int ans = findRotationCount(arr);

    cout << ans << endl;

    return 0;
}
