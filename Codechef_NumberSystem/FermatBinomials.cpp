#include <bits/stdc++.h>

using namespace std;

long long t = 3; // Hardcoded number of test cases
long long a[] = {5, 5, 6}; // Hardcoded values for a
long long b[] = {2, 3, 4}; // Hardcoded values for b

const long long MAXN = 1e6;
const long long MOD = 1e9 + 7;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** Computes x^n modulo m in O(log n) time. */
long long exp(long long x, long long n, long long m) {
    x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long m) {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % m; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log n) time
 */
void inverses(long long m) {
    inv[MAXN] = exp(fac[MAXN], m - 2, m);
    for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % m; }
}

/** Computes nCk mod p */
long long choose1(long long n, long long k, long long m) {
    return fac[n] * inv[k] % m * inv[n - k] % m;
}

int main()
{
    factorial(MOD);
    inverses(MOD);

    // Hardcoded test cases
    for (int i = 0; i < t; i++) {
        cout << choose1(a[i], b[i], MOD) << endl;
    }

    return 0;
}

/*
Hardcoded Input
3
5 2
5 3
6 4
*/
