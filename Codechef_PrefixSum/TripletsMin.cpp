#include <bits/stdc++.h>
using namespace std;

// Function to calculate combinations
inline long long combination2(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Hardcoded input
    int T = 2; // Number of test cases

    // Test case 1
    int N1 = 6, Q1 = 2; // First test case details
    vector<int> A1 = {3, 3, 3, 3, 3, 3}; // First test case array
    vector<int> queries1 = {18, 1}; // Queries for the first test case

    // Test case 2
    int N2 = 4, Q2 = 4; // Second test case details
    vector<int> A2 = {2, 4, 2, 1}; // Second test case array
    vector<int> queries2 = {1, 2, 3, 4}; // Queries for the second test case

    // Process test case 1
    for (int t = 0; t < T; ++t) {
        vector<int> A = (t == 0) ? A1 : A2;
        int N = (t == 0) ? N1 : N2;
        int Q = (t == 0) ? Q1 : Q2;

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
        vector<int> queries = (t == 0) ? queries1 : queries2;
        for (int k : queries) {
            // Find the smallest index i such that prefix[i] >= K
            int index = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();
            cout << A[index] << "\n";
        }
    }

    return 0;
}
