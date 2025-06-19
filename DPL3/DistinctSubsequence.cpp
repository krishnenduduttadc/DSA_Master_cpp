
#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

int subsequenceCounting(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}

