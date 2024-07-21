#include <iostream>
#include <string>
using namespace std;

int countPalindromicSubstrings(const string& s) {
    int n = s.length();
    bool dp[n][n] = {false};  // Initialize the 2D array with false
    int count = 0;

    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) {
                dp[i][j] = true;
            } else if (g == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }

            if (dp[i][j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s = "abccbc";
    cout << countPalindromicSubstrings(s) << endl;
    return 0;
}
