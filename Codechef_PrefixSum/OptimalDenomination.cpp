#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 3; // Number of test cases
    vector<vector<long long>> testCases = {
        {1, 2, 3},  // Test case 1
        {8, 4, 2},  // Test case 2
        {2, 2}      // Test case 3
    };

    for (int t = 0; t < T; ++t) {
        vector<long long> A = testCases[t];
        int N = A.size();

        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        
        vector<long long> prefix(N + 1, 0), suffix(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            prefix[i] = __gcd(prefix[i - 1], A[i - 1]);
        }
        for (int i = N - 1; i >= 0; --i) {
            suffix[i] = __gcd(suffix[i + 1], A[i]);
        }

        long long totalSum = accumulate(A.begin(), A.end(), 0LL);
        long long minNotes = LLONG_MAX;

        for (int i = 0; i < N; ++i) {
            long long currentGCD = __gcd(prefix[i], suffix[i + 1]);
            long long currentSum = totalSum - A[i];
            long long notes = (currentSum / currentGCD) + 1;
            minNotes = min(minNotes, notes);
        }

        cout << minNotes << endl;
    }
    
    return 0;
}
