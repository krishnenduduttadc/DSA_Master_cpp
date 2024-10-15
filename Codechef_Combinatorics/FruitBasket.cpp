#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int t; 
    cin >> t;

    while(t--) {
        int n; 
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ways = 1; 
        for(int i = 0; i < n; i++) {
            // Can pick 0 or 1 or 2 .... a[i] number of i-th fruit
            // So we can pick the i-th fruit in a[i] + 1 number of ways

            ways = (ways * 1ll * (a[i] + 1)) % mod; // Multiply by 1ll to avoid overflow
        }

        cout << ways << "\n";
    }

    return 0;
}

/*
3
4 
2 1 3 5
1
1
2
1 2
*/