#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 5001;

int C[N][N];

int combinations(int n, int k) {
    if(n == k || k == 0) {
        return 1;
    }
    if(k > n) {
        return 0;
    }
    if(C[n][k] != -1) {
        return C[n][k];
    }

    C[n][k] = (combinations(n - 1, k - 1) + combinations(n - 1, k)) % mod;

    return C[n][k];
}

int main() {
    memset(C, -1, sizeof C);
    int t = 1;
    cin >> t;
    while(t--) {
        string s; cin >> s;
        map<char,int> mp;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int ans = 1;
        int left = s.size();

        for(auto [x, y]: mp) {
            ans = (ans * 1ll * combinations(left, y)) % mod;
            left = left - y;
        }

        cout << ans << "\n";
    }
    return 0;
}


/*
4
ab
aa
aA
AAbaz

*/