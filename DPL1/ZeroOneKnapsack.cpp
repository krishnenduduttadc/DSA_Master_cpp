#include <iostream>
#include <vector>

using namespace std;

int knapsack(int n, vector<int> &vals, vector<int> &wts, int cap)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cap; j++)
        {
            if (j >= wts[i - 1])
            {
                int remainingCap = j - wts[i - 1];

                if (dp[i - 1][remainingCap] + vals[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][remainingCap] + vals[i - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][cap];
}

int main()
{
    int n = 5;
    vector<int> vals = {15, 14, 10, 45, 30};
    vector<int> wts = {2, 5, 1, 3, 4};
    int cap = 7;

    int maxVal = knapsack(n, vals, wts, cap);

    cout << "Maximum value that can be obtained: " << maxVal << endl;

    return 0;
}
