
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string& S1, string& S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1]) {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}

