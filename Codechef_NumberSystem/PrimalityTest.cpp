#include <bits/stdc++.h>
using namespace std;

int t,n;

int main() {
    
    bool prime[100000 + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false;
  
    for (int p = 2; p * p <= 100000; p++) {
        if (prime[p] == true) {
            for (int i = 2 * p; i <= 100000; i += p)
                prime[i] = false;
        }
    }

	cin >> t;
    while(t--)
    {
        cin >> n;
        if(prime[n])
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
	return 0;
}


/*
5
23
13
20
1000
99991
*/