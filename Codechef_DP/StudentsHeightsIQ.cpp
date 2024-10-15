#include <bits/stdc++.h>
using namespace std;

int t,n,H[1010], IQ[1010], DP[1010];

int main() {
    
    cin >> t;
    
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>H[i];
        for(int i=1;i<=n;i++)
            cin>>IQ[i];
        
        for(int i=1;i<=n;i++)
        {
            DP[i] = 1;
            for(int j=i-1;j>=1;j--)
            {
                if(H[j]>=H[i])
                    continue;
                if(IQ[j]<=IQ[i])
                    continue;
                DP[i] = max(DP[i], 1 + DP[j]);
            }
        }
        
        int max1 = DP[1];
        for(int i=2;i<=n;i++)
            max1 = max(max1, DP[i]);
        cout << max1 << endl;
    }
    return 0;
}


/*
2
3
1 2 3
3 2 1
4
1 3 2 4
5 6 4 4

*/