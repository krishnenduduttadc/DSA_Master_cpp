#include <iostream>
#include <vector>
using namespace std;

int findTransition(vector<int>& arr) {
    int tp = -1;
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == 1) {
            tp = mid;
            hi = mid - 1; // Look for earlier occurrences on the left side
        } else {
            lo = mid + 1; // If arr[mid] is 0, move to the right half
        }
    }

    return tp;
}

int main() {
    vector<int> arr = {0, 0, 0, 0, 1, 1};

    int ans = findTransition(arr);

    cout << ans << endl;

    return 0;
}
