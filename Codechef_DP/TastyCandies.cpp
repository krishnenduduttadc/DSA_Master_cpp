#include <bits/stdc++.h>
using namespace std;

vector<long long> V0, V1;
long long DP[100010];
long long t, n, A[100010], T[100010];

long long MaxSumSubarray(vector<long long> &V) {
    if (V.size() == 0)
        return (-1e11 - 10);
    DP[0] = V[0];
    for (int i = 1; i < V.size(); i++) {
        DP[i] = max(V[i], V[i] + DP[i - 1]);
    }
    
    long long ret = DP[0];
    for (int i = 1; i < V.size(); i++)
        ret = max(ret, DP[i]);
        
    return ret;
}

int main() {
    // Hardcoded input
    long long testCases = 2; // Number of test cases
    vector<pair<vector<long long>, vector<long long>>> inputs = {
        {{5, -6, 7, 8, 9, 13, -12, 1}, {1, 1, 1, 1, 1, 1, 0, 1}},
        {{5, 6}, {1, 0}}
    };

    for (long long t = 0; t < testCases; t++) {
        n = inputs[t].first.size(); // Size of the current test case
        V0.clear();
        V1.clear();
        // Load A and T from hardcoded input
        A[0] = 0; // 1-based indexing, A[0] is unused
        T[0] = 0; // 1-based indexing, T[0] is unused

        for (int i = 1; i <= n; i++) {
            A[i] = inputs[t].first[i - 1]; // Fill A with the first part of the input
            T[i] = inputs[t].second[i - 1]; // Fill T with the second part of the input
        }

        for (int i = 1; i <= n; i++) {
            if (T[i] == 0)
                V0.push_back(A[i]);
            else
                V1.push_back(A[i]);
        }

        cout << max(MaxSumSubarray(V0), MaxSumSubarray(V1)) << endl;
    }
    return 0;
}
