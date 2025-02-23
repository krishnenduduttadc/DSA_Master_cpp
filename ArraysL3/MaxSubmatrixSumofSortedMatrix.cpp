#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int sumRegion(int row1, int col1, int row2, int col2, vector<vector<int>>& psum) {
    int ans = psum[row2][col2];
    if (row1 > 0) {
        ans -= psum[row1 - 1][col2];
    }
    if (col1 > 0) {
        ans -= psum[row2][col1 - 1];
    }
    if (row1 > 0 && col1 > 0) {
        ans += psum[row1 - 1][col1 - 1];
    }
    return ans;
}

vector<vector<int>> prefix(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> psum(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                psum[i][j] = arr[i][j];
            } else {
                psum[i][j] = psum[i][j - 1] + arr[i][j];
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            psum[i][j] += psum[i - 1][j];
        }
    }

    return psum;
}

int maxSubmatrixSum(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> pf = prefix(arr);

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = sumRegion(i, j, n - 1, m - 1, pf);
            ans = max(ans, temp);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
    };

    int result = maxSubmatrixSum(arr);
    cout << result << endl; // Expected output: 55

    return 0;
}
