#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 2; // Hardcoded number of test cases

    // Hardcoded test cases
    vector<pair<int, vector<vector<int>>>> test_cases = {
        {3, {{1}, {2, 1}, {1, 2, 3}}},
        {4, {{1}, {1, 2}, {4, 1, 2}, {2, 3, 1, 1}}}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        vector<vector<int>> A = test_case.second;
        int DP[101][101] = {0};

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1) {
                    DP[i][j] = (A[i-1][j-1] + DP[i-1][j]); // Adjust for 0-based index
                } else {
                    DP[i][j] = A[i-1][j-1] + max(DP[i-1][j-1], DP[i-1][j]); // Adjust for 0-based index
                }
            }
        }

        int ans = DP[n][1];
        for (int i = 2; i <= n; i++)
            ans = max(ans, DP[n][i]);
        cout << ans << endl;
    }
    
    return 0;
}
