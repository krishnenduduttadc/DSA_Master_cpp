#include <bits/stdc++.h>

using namespace std;

long long t, a, b, m;

long long modexp(long long a, long long b, long long m) 
{
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
	cin>>t;

	while(t--)
	{
		cin >> a >> b >> m;
		cout << modexp(a, b, m) << endl;
	}
}


/*
3
2 4 100
2 4 6
3 2 2
*/