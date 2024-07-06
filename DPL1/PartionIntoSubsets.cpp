#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 4;
    int k = 3;

    if (n == 0 || k == 0 || n < k) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));

    for (int t = 1; t <= k; t++) {
        for (int p = 1; p <= n; p++) {
            if (p < t) {
                dp[t][p] = 0;
            } else if (p == t) {
                dp[t][p] = 1;
            } else {
                dp[t][p] = dp[t - 1][p - 1] + dp[t][p - 1] * t;
            }
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}
