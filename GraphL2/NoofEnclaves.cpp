#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& arr, int i, int j) {
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 0) {
        return;
    }
    arr[i][j] = 0;
    dfs(arr, i + 1, j);
    dfs(arr, i - 1, j);
    dfs(arr, i, j + 1);
    dfs(arr, i, j - 1);
}

int numEnclaves(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && arr[i][j] == 1) {
                dfs(arr, i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int m = 4, n = 4;
    vector<vector<int>> arr = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = numEnclaves(arr);
    cout << result << endl;

    return 0;
}
