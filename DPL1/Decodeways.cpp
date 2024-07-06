#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DecodeWays {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i-1] == '0' && s[i] == '0') {
                dp[i] = 0;
            } else if (s[i-1] == '0' && s[i] != '0') {
                dp[i] = dp[i-1];
            } else if (s[i-1] != '0' && s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = (i >= 2 ? dp[i-2] : 1);
                } else {
                    dp[i] = 0;
                }
            } else {
                int num = stoi(s.substr(i-1, 2));
                if (num <= 26) {
                    dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 1);
                } else {
                    dp[i] = dp[i-1];
                }
            }
        }

        return dp[n-1];
    }
};

int main() {
    DecodeWays solution;

    // Test case
    string str = "21123";
    int result = solution.numDecodings(str);
    cout << "Number of ways to decode '" << str << "': " << result << endl;

    return 0;
}
