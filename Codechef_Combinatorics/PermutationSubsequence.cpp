#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;

        map<int,int> m;

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            m[a]++;
        }

        int sum = 0;
        int prefix = 1;

        for (int i = 1; i <= n; i++){
            prefix = (prefix * 1ll * m[i]) % MOD;
            sum = (sum + prefix) % MOD;
        }

        cout<<sum<<endl;
    }
    return 0;
}


/*
2
5
1 2 3 2 4
6
1 3 5 8 9 8

*/