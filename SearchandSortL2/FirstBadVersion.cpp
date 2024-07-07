#include <iostream>
using namespace std;

// Global variable to simulate the first bad version
int bad = 0;

// Function to check if a version is bad or not
bool isBadVersion(int val) {
    return val >= bad;
}

// Function to find the first bad version using binary search
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

// Utility function to test and print the result
void solve(int n, int fbv) {
    bad = fbv; // Set the global bad version
    cout << firstBadVersion(n) << endl;
}

int main() {
    // Hardcoded input
    int n = 10; // Number of versions
    int fbv = 4; // First bad version

    // Call the solve function to find and print the first bad version
    solve(n, fbv);

    return 0;
}
