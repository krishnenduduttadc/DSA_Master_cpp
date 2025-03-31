#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1 = "cat";
    string s2 = "cut";
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Deleting all characters
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Inserting all characters

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], // Replace
                                    dp[i - 1][j],     // Delete
                                    dp[i][j - 1]});   // Insert
            }
        }
    }

    cout << dp[m][n] << endl; // Output the minimum edit distance

    return 0;
}
