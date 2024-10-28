#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t = 4; // Number of test cases
    vector<pair<int, int>> test_cases = {
        {1, 1},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        int k = test_cases[i].second;

        if (n > k) {
            int ans = 1;
            for (int j = 1; j <= k; j++) {
                ans = (ans * 1ll * j) % MOD;
            }

            cout << ans << "\n";
        } else {
            int ans = 1;
            for (int j = k - n + 1; j <= k; j++) {
                ans = (ans * 1ll * j) % MOD;
            }
            
            cout << ans << "\n";
        }
    }
    return 0;
}
