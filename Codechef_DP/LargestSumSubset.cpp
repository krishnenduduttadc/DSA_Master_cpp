#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 2; // Hardcoded number of test cases
    vector<pair<int, vector<int>>> test_cases = {
        {5, {3, -2, 1, 3, 0}},
        {4, {4, 3, 1, 2}}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        const vector<int>& A = test_case.second;

        int dp[n + 1];
        dp[1] = max(0, A[0]);  // Adjusted index for 0-based vector
        dp[2] = max(dp[1], A[1]);

        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i - 1]);  // Adjusting index again for 0-based vector
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}
