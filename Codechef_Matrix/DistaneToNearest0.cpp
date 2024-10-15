#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions for moving up, down, left, right
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> nearestZeroDistance(vector<vector<int>>& matrix, int N, int M) {
    vector<vector<int>> distance(N, vector<int>(M, -1)); // Initialize distances with -1
    queue<pair<int, int>> q; // Queue for BFS

    // Enqueue all positions that contain 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 0) {
                q.push({i, j});
                distance[i][j] = 0; // Distance to self is 0
            }
        }
    }

    // BFS from all 0s
    while (!q.empty()) {
        auto [x, y] = q.front(); // Get the front element of the queue
        q.pop();

        // Explore all 4 directions
        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            // Check bounds and if the cell is not yet visited
            if (newX >= 0 && newX < N && newY >= 0 && newY < M && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[x][y] + 1; // Update distance
                q.push({newX, newY}); // Enqueue the new position
            }
        }
    }

    return distance; // Return the resulting distance matrix
}

int main() {
    int N, M;
    cin >> N >> M; // Read dimensions of the matrix

    vector<vector<int>> matrix(N, vector<int>(M)); // Initialize the input matrix

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Get the distance matrix and print it
    vector<vector<int>> result = nearestZeroDistance(matrix, N, M);
    
    for (const auto& row : result) {
        for (const auto& dist : row) {
            cout << dist << " "; // Print the distances in the required format
        }
        cout << endl; // New line after each row
    }

    return 0;
}



/*
3 3
0 1 1
0 1 0
1 1 1
*/