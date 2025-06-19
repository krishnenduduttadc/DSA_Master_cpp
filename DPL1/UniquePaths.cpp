#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{

    // Test cases
    vector<vector<int>> testCases = {
        {3, 2}, // m = 3, n = 2
        {7, 3}, // m = 7, n = 3
        {3, 3}, // m = 3, n = 3
        {1, 1}  // m = 1, n = 1
    };

    for (auto &testCase : testCases)
    {
        int m = testCase[0];
        int n = testCase[1];
        int uniquePath = uniquePaths(m, n);
        cout << "For m = " << m << ", n = " << n << ", unique paths = " << uniquePath << endl;
    }

    return 0;
}
