#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {20, 30, 2, 10};
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
    
    for (int g = 0; g < dp.size(); g++) {
        for (int i = 0, j = g; j < dp.size(); i++, j++) {
            if (g == 0) {
                dp[i][j] = arr[i];
            } else if (g == 1) {
                dp[i][j] = max(arr[i], arr[j]);
            } else {
                int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                
                int val = max(val1, val2);
                dp[i][j] = val;
            }
        }
    }
    
    cout << dp[0][arr.size() - 1] << endl;
    
    return 0;
}