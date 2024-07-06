#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(const string& str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prev(n, -1);
    unordered_map<char, int> map;

    for (int i = 0; i < n; i++) {
        char ch = str[i];

        if (map.find(ch) != map.end()) {
            prev[i] = map[ch];
        }

        map[ch] = i;
    }

    vector<int> next(n, -1);
    map.clear();

    for (int i = n - 1; i >= 0; i--) {
        char ch = str[i];

        if (map.find(ch) != map.end()) {
            next[i] = map[ch];
        }

        map[ch] = i;
    }

    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) {
                dp[i][j] = 1;
            } else if (g == 1) {
                dp[i][j] = 2;
            } else {
                char sc = str[i];
                char ec = str[j];

                if (sc != ec) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                } else {
                    int n = next[i];
                    int p = prev[j];

                    if (n > p) {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    } else if (n == p) {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[n + 1][p - 1];
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string str = "ababda";
    cout << solution(str) << endl;
    return 0;
}
