#include <iostream>
#include <string>
#include <algorithm> // For std::max
using namespace std;

const int MAX_M = 100;
const int MAX_N = 100;

int LCS(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    int dp[MAX_M + 1][MAX_N + 1] = {0};

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

int main() {
    string s1 = "abcd";
    string s2 = "abbd";

    cout << LCS(s1, s2) << endl;

    return 0;
}
