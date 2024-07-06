#include <iostream>
#include <string>
using namespace std;

int LongestRepeatingSubsequence(string str) {
    int n = str.length();
    int dp[n + 1][n + 1];

    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            if (i == n || j == n) {
                dp[i][j] = 0;
            } else {
                if (str[i] == str[j] && i != j) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
    }
    return dp[0][0];
}

int main() {
    string str = "abacbc";
    int longestRepeatingSubseqLen = LongestRepeatingSubsequence(str);
    cout << longestRepeatingSubseqLen << endl;

    return 0;
}
