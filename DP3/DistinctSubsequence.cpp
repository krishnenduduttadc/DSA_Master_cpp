
#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m) {
    // Create a 2D DP array to store the count of distinct subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first column: s1 can't match any non-empty s2
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, we have two options:
                // 1. Match the current characters and move diagonally (dp[i-1][j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                // If the characters don't match, we can only leave the current character in s1
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The value at dp[n][m] contains the count of distinct subsequences
    return dp[n][m];
}

int main() {
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}

