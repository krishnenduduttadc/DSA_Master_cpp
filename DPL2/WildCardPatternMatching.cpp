#include <iostream>
#include <vector>
using namespace std;

bool sol(string str, string pattern) {
    int m = pattern.length();
    int n = str.length();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[m][n] = true; // Base case: both pattern and string are empty

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (pattern[i] == '*') {
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
            } else if (pattern[i] == '?') {
                dp[i][j] = dp[i + 1][j + 1];
            } else if (pattern[i] == str[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[0][0];
}

int main() {
    string s1 = "baaabab";
    string s2 = "ba*a";
    cout << sol(s1, s2) << endl;
    return 0;
}
