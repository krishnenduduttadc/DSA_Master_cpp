#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Initialize a boolean array for prime checking
    bool prime[100000 + 1];
    memset(prime, true, sizeof(prime));
    prime[1] = false; // 1 is not a prime number

    // Sieve of Eratosthenes to find all primes up to 100000
    for (int p = 2; p * p <= 100000; p++) {
        if (prime[p]) {
            for (int i = 2 * p; i <= 100000; i += p)
                prime[i] = false;
        }
    }

    // Hardcoded input
    int t = 5; // Number of test cases
    int testCases[] = {23, 13, 20, 1000, 99991}; // The test cases

    for (int i = 0; i < t; i++) {
        int n = testCases[i]; // Get the current test case
        if (prime[n])
            cout << "yes\n"; // Output "yes" if n is prime
        else
            cout << "no\n"; // Output "no" if n is not prime
    }

    return 0;
}

/*
Hardcoded Input:
5
23
13
20
1000
99991
*/
