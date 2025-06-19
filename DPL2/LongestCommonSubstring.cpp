#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LongestCommonSubstring(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLen;
}

int main() {
    string s1 = "xyzabcp";
    string s2 = "pqabcxy";

    cout << LongestCommonSubstring(s1, s2) << endl;

    return 0;
}
