#include <bits/stdc++.h>

using namespace std;

// Function to perform DFS and calculate the area of the island
int dfs(vector<vector<int>>& matrix, int i, int j, int N, int M) {
    // Check if we are out of bounds or if the cell is water (0)
    if (i < 0 || i >= N || j < 0 || j >= M || matrix[i][j] == 0) {
        return 0;
    }

    // Mark the cell as visited by changing it to 0 (water)
    matrix[i][j] = 0;

    // Initialize the area of this island
    int area = 1;

    // Explore the 4 directions (up, down, left, right)
    area += dfs(matrix, i - 1, j, N, M); // up
    area += dfs(matrix, i + 1, j, N, M); // down
    area += dfs(matrix, i, j - 1, N, M); // left
    area += dfs(matrix, i, j + 1, N, M); // right

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& matrix, int N, int M) {
    int maxArea = 0;

    // Traverse the entire matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // If we find a '1', it's an unvisited part of an island
            if (matrix[i][j] == 1) {
                // Perform DFS to find the area of this island
                int area = dfs(matrix, i, j, N, M);
                // Update the maximum area
                maxArea = max(maxArea, area);
            }
        }
    }

    return maxArea;
}

int main() {
    int N, M;
    cin >> N >> M;  // Read the dimensions of the matrix

    vector<vector<int>> matrix(N, vector<int>(M));  // Initialize the matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Output the maximum area of the island
    cout << maxAreaOfIsland(matrix, N, M) << endl;

    return 0;
}



/*
3 3
0 1 1
0 1 1
0 1 1

*/