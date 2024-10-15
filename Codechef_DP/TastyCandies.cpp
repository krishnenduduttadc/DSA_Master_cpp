#include <bits/stdc++.h>
using namespace std;

vector<long long> V0, V1;
long long DP[100010];
long long t, n, A[100010], T[100010];

long long MaxSumSubarray(vector<long long> &V)
{
    if(V.size()==0)
        return (-1e11-10);
    DP[0] = V[0];
    for(int i=1;i<V.size();i++)
    {
        DP[i] = max(V[i], V[i] + DP[i-1]);
    }
    
    long long ret = DP[0];
    for(int i=1;i<V.size();i++)
        ret = max(ret, DP[i]);
        
    return ret;
}

int main() {
    
    cin >> t;
    
    while(t--)
    {
        cin>>n;
        V0.clear();
        V1.clear();
        for(int i=1;i<=n;i++)
            cin>>A[i];
        for(int i=1;i<=n;i++)
            cin>>T[i];
            
        for(int i=1;i<=n;i++)
        {
            if(T[i]==0)
                V0.push_back(A[i]);
            else
                V1.push_back(A[i]);
        }
        
        cout<<max(MaxSumSubarray(V0), MaxSumSubarray(V1)) << endl;
    }
    return 0;
}

/*
2  
8  
5 -6 7 8 9 13 -12 1  
1 1 1 1 1 1 0 1  
2   
5 6  
1 0  

*/