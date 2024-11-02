#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minMinutesToRotApples(vector<vector<int>>& grid, int N, int M) {
    queue<pair<int, int>> rottenQueue;
    int freshCount = 0;
    int minutes = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 2) {
                rottenQueue.push({i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    while (!rottenQueue.empty() && freshCount > 0) {
        int size = rottenQueue.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = rottenQueue.front();
            rottenQueue.pop();

            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newX < N && newY >= 0 && newY < M && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    freshCount--;
                    rottenQueue.push({newX, newY});
                }
            }
        }
        minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}

int main() {
    int N = 3, M = 4;
    
    vector<vector<int>> grid = {
        {0, 2, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };

    cout << minMinutesToRotApples(grid, N, M) << endl;

    return 0;
}
