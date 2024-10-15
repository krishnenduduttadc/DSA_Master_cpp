#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions for moving up, down, left, right
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minMinutesToRotApples(vector<vector<int>>& grid, int N, int M) {
    queue<pair<int, int>> rottenQueue; // Queue for BFS
    int freshCount = 0; // Count of fresh apples
    int minutes = 0; // Time elapsed

    // Initialize the queue with all rotten apples and count fresh apples
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    // BFS to spread rot
    while (!rottenQueue.empty() && freshCount > 0) {
        int size = rottenQueue.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = rottenQueue.front();
            rottenQueue.pop();

            // Check all 4 directions
            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check bounds and if the cell is a fresh apple
                if (newX >= 0 && newX < N && newY >= 0 && newY < M && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Mark it as rotten
                    freshCount--; // Decrease the count of fresh apples
                    rottenQueue.push({newX, newY}); // Enqueue the new rotten apple
                }
            }
        }
        minutes++; // Increment the minutes after processing the current layer
    }

    // If there are still fresh apples left, return -1
    return freshCount == 0 ? minutes : -1;
}

int main() {
    int N, M;
    cin >> N >> M; // Read dimensions

    vector<vector<int>> grid(N, vector<int>(M)); // Initialize the grid

    // Read the matrix elements
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Output the minimum minutes required
    cout << minMinutesToRotApples(grid, N, M) << endl;

    return 0;
}



/*
3 4
0 2 1 1  
1 1 0 1 
1 1 0 1

*/