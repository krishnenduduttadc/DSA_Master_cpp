#include<bits/stdc++.h>
using namespace std;

int climb(int n){
   if(n==1 || n==2) {
       return n;
   }
   int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int res=climb(n);
    cout<<res;
    return 0;
}