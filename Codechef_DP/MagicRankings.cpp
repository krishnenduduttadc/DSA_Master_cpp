#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 2; // Hardcoded number of test cases
    vector<pair<int, vector<vector<int>>>> test_cases = {
        {2, {{0, -4}, {8, 0}}}, 
        {2, {{0, -45}, {-3, 0}}}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        const vector<vector<int>>& A = test_case.second;
        int DP[101][101];

        DP[1][1] = A[0][0]; // Adjust for 0-based indexing

        for (int i = 2; i <= n; i++)
            DP[1][i] = (DP[1][i - 1] + A[0][i - 1]); // Adjust for 0-based indexing

        for (int i = 2; i <= n; i++) {
            DP[i][1] = DP[i - 1][1] + A[i - 1][0]; // Adjust for 0-based indexing
            for (int j = 2; j <= n; j++)
                DP[i][j] = A[i - 1][j - 1] + max(DP[i - 1][j], DP[i][j - 1]); // Adjust for 0-based indexing
        }

        if (DP[n][n] < 0)
            cout << "Bad Judges\n";
        else {
            cout << std::fixed;
            cout << std::setprecision(9) << DP[n][n] / (long double)(2 * n - 3) << endl;
        }
    }

    return 0;
}
