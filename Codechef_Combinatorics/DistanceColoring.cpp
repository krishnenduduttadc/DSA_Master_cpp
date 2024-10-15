#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int t; cin >> t;
    while(t--) {
        int n, k; 
        cin >> n >> k;

        if(n > k) {
            int ans = 1;
            for(int i = 1; i <= k; i++) {
                ans = (ans * 1ll * i) % MOD;
            }

            cout << ans << "\n";
        }
        else {
            int ans = 1;
            for(int i = k - n + 1; i <= k; i++) {
                ans = (ans * 1ll * i) % MOD;
            }
            
            cout << ans << "\n";
        }
    }
    return 0;
}


/*
4
1 1
1 2
2 1
2 2

*/