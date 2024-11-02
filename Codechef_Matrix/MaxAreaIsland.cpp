#include <bits/stdc++.h>

using namespace std;

// Function to perform DFS and calculate the area of the island
int dfs(vector<vector<int>>& matrix, int i, int j, int N, int M) {
    if (i < 0 || i >= N || j < 0 || j >= M || matrix[i][j] == 0) {
        return 0;
    }

    matrix[i][j] = 0;

    int area = 1;
    area += dfs(matrix, i - 1, j, N, M); // up
    area += dfs(matrix, i + 1, j, N, M); // down
    area += dfs(matrix, i, j - 1, N, M); // left
    area += dfs(matrix, i, j + 1, N, M); // right

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& matrix, int N, int M) {
    int maxArea = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 1) {
                int area = dfs(matrix, i, j, N, M);
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {
    int N = 3, M = 3;

    vector<vector<int>> matrix = {
        {0, 1, 1},
        {0, 1, 1},
        {0, 1, 1}
    };

    cout << maxAreaOfIsland(matrix, N, M) << endl;

    return 0;
}
