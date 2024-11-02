#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;
bool prime[MAXN + 5];
int tot_primes_till[MAXN + 5];

void sieve() {
    int n = MAXN;
    fill(begin(prime), end(prime), true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= n; i++) {
        tot_primes_till[i] = tot_primes_till[i - 1];

        if (!prime[i])
            continue;

        tot_primes_till[i]++;

        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    // Hardcoded number of test cases
    int tests = 4;
    
    // Hardcoded test cases
    vector<pair<int, int>> test_cases = {
        {2, 10},
        {5, 12},
        {34, 43},
        {57, 63}
    };

    for (int t = 0; t < tests; t++) {
        int X = test_cases[t].first;
        int Y = test_cases[t].second;

        int ans = Y - X - (tot_primes_till[Y] - tot_primes_till[X + 1]);

        cout << ans << "\n"; // Output the result for each test case
    }

    return 0;
}
