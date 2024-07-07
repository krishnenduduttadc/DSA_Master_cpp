#include <iostream>

using namespace std;

int sqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int low = 1, high = x, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long mSqr = (long long) mid * mid; // Use long long to avoid integer overflow

        if (mSqr == x) {
            return mid;
        } else if (mSqr > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int main() {
    cout << sqrt(37) << endl;
    return 0;
}
