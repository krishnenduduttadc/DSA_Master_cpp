#include <bits/stdc++.h>

#define int long long int
#define double double_t
#define INF 1e18
using namespace std;

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

const int mod = 1000000000 + 7;

int power(int x, int y, int MOD = mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power((x * x) % MOD, y / 2, MOD) % MOD;
    } else {
        return (x * power((x * x) % MOD, (y - 1) / 2, MOD) % MOD) % MOD;
    }
}

int inverse(int n, int p) {
    return power(n, p - 2, p);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    vector<tuple<int, vector<int>, vector<int>>> test_cases = {
        {5, {0, 1, 2, 0, 2}, {5, 6, 7, 8, 2}}
    };

    for (auto& [n, c, w] : test_cases) {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[c[i]] = -1;
        }
        int maxSum = 0;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (mp[c[i]] == -1) {
                sum += w[i];
                mp[c[i]] = i;
            } else {
                while (start <= mp[c[i]]) {
                    sum -= w[start++];
                }
                sum = sum + w[i];
                mp[c[i]] = i;
            }
            maxSum = max(maxSum, sum);
        }
        cout << maxSum << "\n";
    }

    return 0;
}
