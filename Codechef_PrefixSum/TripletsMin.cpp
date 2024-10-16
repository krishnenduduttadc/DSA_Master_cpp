#include <bits/stdc++.h>
using namespace std;

// Function to calculate combinations
inline long long combination2(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Sort the array to easily compute the triplet minimums
        sort(A.begin(), A.end());

        vector<long long> prefix(N, 0);
        for (int i = 0; i < N; ++i) {
            if (N - i - 1 >= 2) {
                prefix[i] = combination2(N - i - 1);
            }
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }

        // Respond to each query
        while (Q--) {
            int K;
            cin >> K;
            // Find the smallest index i such that prefix[i] >= K
            int index = lower_bound(prefix.begin(), prefix.end(), K) - prefix.begin();
            cout << A[index] << "\n";
        }
    }

    return 0;
}

/*
2
6 2
3 3 3 3 3 3
18
1
4 4
2 4 2 1
1
2
3
4

*/