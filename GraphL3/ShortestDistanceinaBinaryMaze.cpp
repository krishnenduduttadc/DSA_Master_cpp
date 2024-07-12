#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // Structure to represent coordinates (x, y)
    struct Pair {
        int x, y;
        Pair(int _x, int _y) : x(_x), y(_y) {}
    };

    // Function to check if the current position is valid
    bool isValid(int x, int y, int rows, int cols, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
        return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1 && !visited[x][y];
    }

    // Function to find the shortest distance in the binary maze
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size();
        int cols = maze[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<Pair> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

        q.push(Pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        distance[start[0]][start[1]] = 0;

        while (!q.empty()) {
            Pair current = q.front();
            q.pop();

            for (auto& dir : directions) {
                int newX = current.x;
                int newY = current.y;
                int steps = 0;

                while (isValid(newX + dir[0], newY + dir[1], rows, cols, maze, visited)) {
                    newX += dir[0];
                    newY += dir[1];
                    steps++;
                }

                if (!visited[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push(Pair(newX, newY));
                    distance[newX][newY] = min(distance[newX][newY], distance[current.x][current.y] + steps);
                }
            }
        }

        return (visited[destination[0]][destination[1]]) ? distance[destination[0]][destination[1]] : -1;
    }
};

int main() {
    vector<vector<int>> maze = {
            {1, 0, 1, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 1, 0, 1}
    };

    vector<int> start = {0, 0};
    vector<int> destination = {4, 4};

    Solution solution;
    int result = solution.shortestDistance(maze, start, destination);

    cout << "Shortest Distance: " << result << endl;

    return 0;
}
