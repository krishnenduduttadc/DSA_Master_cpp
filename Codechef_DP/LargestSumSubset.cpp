#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int A[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }

        int dp[n + 1];
        dp[1] = max(0, A[1]);
        dp[2] = max(dp[1], A[2]);

        for (int i = 3; i < n + 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";

    }

}


/*
2
5
3 -2 1 3 0
4
4 3 1 2
*/