#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// Structure for a node in the grid
struct Node {
    int x, y, h;
};

// Custom comparator for priority queue (min-heap)
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.h > b.h; // Lower heuristic (h) value has higher priority
    }
};

// Directions for moving up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Manhattan Distance Heuristic
int heuristic(int x, int y, int goalX, int goalY) {
    return abs(x - goalX) + abs(y - goalY);
}

// Check if the new position is valid
bool isValid(int x, int y, vector<vector<int>>& grid) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && grid[x][y] == 0;
}

// Best-First Search Algorithm
vector<pair<int, int>> bestFirstSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    priority_queue<Node, vector<Node>, Compare> openSet;
    vector<vector<bool>> visited(3, vector<bool>(3, false));
    vector<vector<pair<int, int>>> parent(3, vector<pair<int, int>>(3, {-1, -1}));

    openSet.push({start.first, start.second, heuristic(start.first, start.second, goal.first, goal.second)});
    visited[start.first][start.second] = true;

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goal.first && current.y == goal.second) break; // Goal reached

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValid(newX, newY, grid) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                parent[newX][newY] = {current.x, current.y};
                openSet.push({newX, newY, heuristic(newX, newY, goal.first, goal.second)});
            }
        }
    }

    // Reconstruct the path
    vector<pair<int, int>> path;
    pair<int, int> p = goal;
    while (p != start && parent[p.first][p.second] != make_pair(-1, -1)) {
        path.push_back(p);
        p = parent[p.first][p.second];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {2, 2};

    vector<pair<int, int>> path = bestFirstSearch(grid, start, goal);

    cout << "Path found: ";
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
