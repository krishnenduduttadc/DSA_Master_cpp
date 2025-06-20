#include <iostream>
using namespace std;

int bad = 0;

bool isBadVersion(int val) {
    return val >= bad;
}

int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    int fbv = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (isBadVersion(mid)) {
            fbv = mid;
            hi = mid - 1; // Search in the left half for earlier bad versions
        } else {
            lo = mid + 1; // Search in the right half
        }
    }

    return fbv;
}

void solve(int n, int fbv) {
    bad = fbv; // Set the global bad version
    cout << firstBadVersion(n) << endl;
}

int main() {
    int n = 10; // Number of versions
    int fbv = 4; // First bad version

    solve(n, fbv);
    return 0;
}
