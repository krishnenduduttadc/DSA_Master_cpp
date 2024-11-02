#include <bits/stdc++.h>

using namespace std;

long long t = 3; // Hardcoded number of test cases
long long a[] = {2, 2, 3}; // Hardcoded values for a
long long b[] = {4, 4, 2}; // Hardcoded values for b
long long m[] = {100, 6, 2}; // Hardcoded values for m

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
    // Hardcoded test cases
    for (int i = 0; i < t; i++) {
        cout << modexp(a[i], b[i], m[i]) << endl;
    }

    return 0;
}

/*
Hardcoded Input:
3
2 4 100
2 4 6
3 2 2
*/
