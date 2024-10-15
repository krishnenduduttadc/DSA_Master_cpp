#include <bits/stdc++.h>
using namespace std;

int T,n,DP[101][101],A[101][101];

int main() {
    
    cin >> T;
    
    while(T--)
    {
        cin >> n;
        
        DP[0][1] = 0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cin>>A[i][j];
                if(j==1)
                    DP[i][j] = (A[i][j] + DP[i-1][j]);
                else
                    DP[i][j] = A[i][j] + max(DP[i-1][j-1],DP[i-1][j]);
            }
        }
        
        int ans = DP[n][1];
        for(int i=2;i<=n;i++)
            ans = max(ans, DP[n][i]);
        cout<<ans<<endl;
    }
	return 0;
}


/*
2
3
1
2 1
1 2 3
4
1
1 2
4 1 2
2 3 1 1

*/