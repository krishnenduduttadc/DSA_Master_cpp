#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1 = "cat";
    string s2 = "cut";
    int m = s1.length();
    int n = s2.length();

    // Initialize the 2D array with dimensions (m+1) x (n+1)
    int dp[m + 1][n + 1] = {0};

    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // If s1 is empty, insert all characters of s2
            } else if (j == 0) {
                dp[i][j] = i; // If s2 is empty, remove all characters of s1
            } else {
                int f1 = 1 + dp[i - 1][j - 1]; // Replace
                int f2 = 1 + dp[i - 1][j];     // Delete
                int f3 = 1 + dp[i][j - 1];     // Insert
                dp[i][j] = min({f1, f2, f3});
            }
        }
    }

    cout << dp[m][n] << endl; // Output the result

    return 0;
}
