#include <bits/stdc++.h>
using namespace std;


long long isTotalCoins(long long h) {
    return (h * (h + 1)) / 2;
}


int main() {
	int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        long long lo = 1, hi = n, mid;
        
        // Binary search for the maximum height
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


/*
3
3
5
7
*/