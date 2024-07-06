#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s1 = "cat";
    string s2 = "cut";

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                int f1 = 1 + dp[i-1][j-1]; // replace
                int f2 = 1 + dp[i-1][j];   // delete
                int f3 = 1 + dp[i][j-1];   // insert
                dp[i][j] = min({f1, f2, f3});
            }
        }
    }

    cout << dp[dp.size()-1][dp[0].size()-1] << endl;

    return 0;
}