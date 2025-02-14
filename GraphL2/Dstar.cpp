#include <bits/stdc++.h>


using namespace std;

struct Node {
    int x, y, g;
    bool updated;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.g > b.g;
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, vector<vector<int>>& grid) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && grid[x][y] == 0;
}

vector<pair<int, int>> dStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    priority_queue<Node, vector<Node>, Compare> openSet;
    vector<vector<int>> cost(3, vector<int>(3, INT_MAX));
    vector<vector<pair<int, int>>> parent(3, vector<pair<int, int>>(3, {-1, -1}));
    
    cost[end.first][end.second] = 0;
    openSet.push({end.first, end.second, 0, false});
    
    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();
        
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (isValid(newX, newY, grid)) {
                int newCost = current.g + 1;
                if (newCost < cost[newX][newY]) {
                    cost[newX][newY] = newCost;
                    parent[newX][newY] = {current.x, current.y};
                    openSet.push({newX, newY, newCost, false});
                }
            }
        }
    }
    
    vector<pair<int, int>> path;
    pair<int, int> p = start;
    int safety = 10; // Prevent infinite loop
    while (p != end && parent[p.first][p.second] != make_pair(-1, -1) && safety--) {
        path.push_back(p);
        p = parent[p.first][p.second];
    }
    if (p == end) path.push_back(end);
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
    pair<int, int> end = {2, 2};
    
    vector<pair<int, int>> path = dStar(grid, start, end);
    cout << "Initial Path: ";
    for (auto p : path) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    // Introduce a new obstacle
    grid[1][2] = 1;
    cout << "Obstacle added at (1,2). Recomputing..." << endl;
    path = dStar(grid, start, end);
    
    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Updated Path: ";
        for (auto p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    return 0;
}
