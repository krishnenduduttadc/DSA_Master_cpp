#include <bits/stdc++.h>
using namespace std;

int t, n, A[51];

int gcd(int a,int b) {
  int R;
  while ((a % b) > 0)  {
    R = a % b;
    a = b;
    b = R;
  }
  return b;
}

int main() {
    
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    for(int i=1; i<=n; i++)
	    {
	        cin>>A[i];
	    }
	    int g = A[1];
	    for(int i=2;i<=n;i++)
	        g = gcd(g, A[i]);
	    for(int i=1;i<=n;i++)
	        cout << A[i] / g <<" ";
	    cout << endl;
	}
	return 0;
}

/*
3
2 4 4
3 2 3 4
4 3 15 9 6
*/