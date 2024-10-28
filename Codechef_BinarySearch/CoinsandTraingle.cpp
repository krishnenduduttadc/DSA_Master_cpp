#include <bits/stdc++.h>
using namespace std;

long long isTotalCoins(long long h) {
    return (h * (h + 1)) / 2;
}

int main() {
    int t = 3;
    vector<long long> test_cases = {3, 5, 7};

    for (int i = 0; i < t; i++) {
        long long n = test_cases[i];
        long long ans = 0;
        long long lo = 1, hi = n, mid;

        while(lo <= hi) {
            mid = (hi + lo) / 2;
            if(isTotalCoins(mid) <= n) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << endl;
    }
}
