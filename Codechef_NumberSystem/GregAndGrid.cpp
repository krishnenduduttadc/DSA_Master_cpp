#include <bits/stdc++.h>
using namespace std;

int SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    int total = 0;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            total++; // Count the prime number
            for (int i = 2 * p; i <= n; i += p)
                prime[i] = false; // Mark multiples of p as non-prime
        }
    }
    return total;
}

int main() {
    int n1 = 3; // Hardcoded value for n1
    int m1 = 4; // Hardcoded value for m1

    // Calculate the total number of primes up to n1 + m1
    cout << SieveOfEratosthenes(n1 + m1) << endl;

    return 0;
}

/*
Hardcoded Input:
3 4
*/
