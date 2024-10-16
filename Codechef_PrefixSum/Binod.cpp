#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, Q;
        cin >> N >> Q; // Number of elements and number of queries

        vector < long long > A(N + 1); // Array of elements, 1-based indexing
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
        }

        // Prefix sum arrays: pref[k][i] gives the count of numbers with k-th bit set from A[1] to A[i]
        vector < vector < int >> pref(60, vector < int > (N + 1, 0));

        for (int i = 1; i <= N; ++i) {
            for (int k = 0; k < 60; ++k) {
                pref[k][i] = pref[k][i - 1] + ((A[i] >> k) & 1);
            }
        }

        // Processing each query
        while (Q--) {
            int k, L1, R1, L2, R2;
            cin >> k >> L1 >> R1 >> L2 >> R2;

            // Count of numbers with k-th bit set in [L1, R1] and [L2, R2]
            int S1 = pref[k][R1] - pref[k][L1 - 1];
            int S2 = pref[k][R2] - pref[k][L2 - 1];

            // Count of numbers with k-th bit unset in [L1, R1] and [L2, R2]
            int U1 = (R1 - L1 + 1) - S1;
            int U2 = (R2 - L2 + 1) - S2;

            // Answer for this query
            long long answer = (long long) S1 * U2 + (long long) U1 * S2;
            cout << answer << "\n";
        }
    }

    return 0;
}

/*
2
5 2
1 2 4 3 2
1 1 3 5 5
2 1 2 3 5
6 2
3 5 6 13 12 20
1 1 4 5 6
3 2 3 4 6
*/