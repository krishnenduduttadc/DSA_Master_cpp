#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; 
    dp[1] = 1; 

    for (int i = 2; i <= n; i++) {
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        int twoDigit = stoi(s.substr(i - 2, 2));
        if (twoDigit >= 10 && twoDigit <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    string str = "21123";
    int result = numDecodings(str);
    cout << "Number of ways to decode '" << str << "': " << result << endl;

    return 0;
}
