#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& prices) {
    vector<int> np(prices.size() + 1);
    for (int i = 0; i < prices.size(); i++) {
        np[i + 1] = prices[i];
    }

    vector<int> dp(np.size());
    dp[0] = 0;
    dp[1] = np[1];

    for (int i = 2; i < dp.size(); i++) {
        dp[i] = np[i];

        int li = 1;
        int ri = i - 1;
        while (li <= ri) {
            if (dp[li] + dp[ri] > dp[i]) {
                dp[i] = dp[li] + dp[ri];
            }

            li++;
            ri--;
        }
    }

    return dp[dp.size() - 1];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << solution(prices) << endl;

    return 0;
}