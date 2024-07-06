#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {4, 2, 7, 1, 3};
    int n = arr.size();
    int tar = 10;
    vector<vector<bool>> dp(n + 1, vector<bool>(tar + 1, false));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= tar; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (j == 0) {
                dp[i][j] = true;
            } else {
                if (dp[i - 1][j] == true) {
                    dp[i][j] = true;
                } else {
                    int val = arr[i - 1];
                    if (j >= val) {
                        if (dp[i - 1][j - val] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    cout << (dp[n][tar] ? "true" : "false") << endl;
    return 0;
}
