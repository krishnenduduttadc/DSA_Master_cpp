#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 5001;

int C[N][N];

int combinations(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    if (C[n][k] != -1) {
        return C[n][k];
    }

    C[n][k] = (combinations(n - 1, k - 1) + combinations(n - 1, k)) % mod;

    return C[n][k];
}

int main() {
    memset(C, -1, sizeof C);
    vector<string> test_cases = {"ab", "aa", "aA", "AAbaz"};
    
    for (const string& s : test_cases) {
        map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        int ans = 1;
        int left = s.size();

        for (auto& p : mp) {
            ans = (ans * 1ll * combinations(left, p.second)) % mod;
            left -= p.second;
        }

        cout << ans << "\n";
    }
    return 0;
}
