#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(string &s1, int i, string &s2, int j, string &s3, int k, vector<vector<vector<int>>> &dp) {
    if (i == -1 || j == -1 || k == -1)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s1[i] == s2[j] && s1[i] == s3[k]) {
        int x = LCS(s1, i - 1, s2, j - 1, s3, k - 1, dp);
        dp[i][j][k] = x + 1;
        return dp[i][j][k];
    } else {
        int x = LCS(s1, i - 1, s2, j, s3, k, dp);
        int y = LCS(s1, i, s2, j - 1, s3, k, dp);
        int z = LCS(s1, i, s2, j, s3, k - 1, dp);
        dp[i][j][k] = max({x, y, z});
        return dp[i][j][k];
    }
}

int LCSof3(string A, string B, string C) {
    int n1 = A.length();
    int n2 = B.length();
    int n3 = C.length();

    vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));

    return LCS(A, n1 - 1, B, n2 - 1, C, n3 - 1, dp);
}

int main() {
    string A = "geeks";
    string B = "geeksfor";
    string C = "geeksforgeeks";

    int result = LCSof3(A, B, C);

    cout << "Length of LCS of (" << A << ", " << B << ", " << C << ") is: " << result << endl;

    return 0;
}
