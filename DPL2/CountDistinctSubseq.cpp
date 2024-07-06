#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countDistinctSubsequences(const string& str) {
    vector<int> dp(str.length() + 1, 0);
    dp[0] = 1; // Empty subsequence
    unordered_map<char, int> lastOccurrence;

    for (int i = 1; i < dp.size(); i++) {
        dp[i] = 2 * dp[i - 1];
        char ch = str[i - 1];
        if (lastOccurrence.find(ch) != lastOccurrence.end()) {
            int j = lastOccurrence[ch];
            dp[i] = dp[i] - dp[j - 1];
        }
        lastOccurrence[ch] = i;
    }
    return dp[str.length()] - 1;
}

int main() {
    string str = "abc";
    cout << countDistinctSubsequences(str) << endl;
    return 0;
}
