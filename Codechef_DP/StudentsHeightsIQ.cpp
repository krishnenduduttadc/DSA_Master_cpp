#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 2; // Hardcoded number of test cases

    // Hardcoded test cases
    vector<pair<int, pair<vector<int>, vector<int>>>> test_cases = {
        {3, {{1, 2, 3}, {3, 2, 1}}}, 
        {4, {{1, 3, 2, 4}, {5, 6, 4, 4}}}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case.first;
        const vector<int>& H = test_case.second.first;
        const vector<int>& IQ = test_case.second.second;

        int DP[1010] = {0};

        for (int i = 1; i <= n; i++) {
            DP[i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                if (H[j - 1] >= H[i - 1]) // Adjusting for 0-based index
                    continue;
                if (IQ[j - 1] <= IQ[i - 1]) // Adjusting for 0-based index
                    continue;
                DP[i] = max(DP[i], 1 + DP[j]);
            }
        }

        int max1 = DP[1];
        for (int i = 2; i <= n; i++)
            max1 = max(max1, DP[i]);

        cout << max1 << endl;
    }

    return 0;
}
