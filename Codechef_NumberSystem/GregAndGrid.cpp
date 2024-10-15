#include <bits/stdc++.h>
using namespace std;

int SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    int total = 0;
    memset(prime, true, sizeof(prime));
    prime[1] = false;
  
    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            total++;
            for (int i = 2 * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return total;
}


int main() {
	int n1, m1;
	cin >> n1 >> m1;
	
	cout << SieveOfEratosthenes(n1+m1) << endl;
	return 0;
}

/*
3 4
*/