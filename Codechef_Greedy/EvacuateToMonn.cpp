#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, h;
		cin>>n>>m>>h;
		vector <int> a(n), b(m);
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		sort(a.begin(), a.end(), greater <int> ());
		sort(b.begin(), b.end(), greater <int> ());
		long long sum=0;
		for(int i=0;i<min(n, m);i++)
			sum+=min(1ll*a[i], 1ll*b[i]*h);
		cout<<sum<<"\n";
	}
}

/*
3
1 2 2
100
20 40
2 1 2
10 20
11
3 2 1
30 30 30
40 20

*/