#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t = 2;
    vector<vector<int>> test_cases = {
        {1, 2, 3, 2, 4},
        {1, 3, 5, 8, 9, 8}
    };

    for (int i = 0; i < t; i++) {
        int n = test_cases[i].size();
        map<int, int> m;

        for (int a : test_cases[i]) {
            m[a]++;
        }

        int sum = 0;
        int prefix = 1;

        for (int j = 1; j <= n; j++) {
            prefix = (prefix * 1ll * m[j]) % MOD;
            sum = (sum + prefix) % MOD;
        }

        cout << sum << endl;
    }
    return 0;
}
