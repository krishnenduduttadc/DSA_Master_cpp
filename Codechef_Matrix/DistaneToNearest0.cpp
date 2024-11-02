#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> nearestZeroDistance(vector<vector<int>>& matrix, int N, int M) {
    vector<vector<int>> distance(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == 0) {
                q.push({i, j});
                distance[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return distance;
}

int main() {
    int N = 3, M = 3;
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = nearestZeroDistance(matrix, N, M);
    
    for (const auto& row : result) {
        for (const auto& dist : row) {
            cout << dist << " ";
        }
        cout << endl;
    }

    return 0;
}
