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
    while(t) {
        int n, k; cin >> n >> k;
        if(n == 0 && k == 0) 
            break;
        int ans = (combinations(n - 2, k / 2) * 2ll * combinations(n - 2, (k - 1) / 2)) % mod;
        cout << ans << "\n";
    }
    return 0;
}


/*
4 2
4 3
5 3
0 0
*/