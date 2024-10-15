#include <bits/stdc++.h>
using namespace std;

int t,n,A[101][101], DP[101][101];

int main() {
	
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            cin>>A[i][j];
	        }
	    }
	    
	    DP[1][1] = A[1][1];
	    for(int i=2;i<=n;i++)
	        DP[1][i] = (DP[1][i-1] + A[1][i]);
	    for(int i=2;i<=n;i++)
	    {
	        DP[i][1] = DP[i-1][1] + A[i][1];
	        for(int j=2;j<=n;j++)
	            DP[i][j] = A[i][j] + max(DP[i-1][j], DP[i][j-1]);
	    }
	    if(DP[n][n] < 0)
	        cout<<"Bad Judges\n";
	    else
	    {
	         cout << std::fixed;
	         cout << std::setprecision(9) << DP[n][n]/(long double)(2*n-3)<<endl;
	    }
	}
	
	
	return 0;
}


/*
2
2
0 -4
8 0
2
0 -45
-3  0

*/