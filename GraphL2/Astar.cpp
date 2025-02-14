#include <bits/stdc++.h>


using namespace std;

struct Node {
    int x, y;
    int g, h, f;
    Node* parent;
};

bool isValid(int x, int y, vector<vector<int>>& grid) {
    return x >= 0 && x < 3 && y >= 0 && y < 3 && grid[x][y] == 0;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

vector<pair<int, int>> getPath(Node node) {
    vector<pair<int, int>> path;
    while (node.parent != nullptr) {
        path.push_back({node.x, node.y});
        node = *node.parent;
    }
    path.push_back({node.x, node.y});
    reverse(path.begin(), path.end());
    return path;
}

vector<pair<int, int>> aStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    vector<vector<bool>> visited(3, vector<bool>(3, false));
    queue<Node> openSet;
    
    Node startNode = {start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second), 0, nullptr};
    openSet.push(startNode);
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!openSet.empty()) {
        Node current = openSet.front();
        openSet.pop();
        
        if (current.x == end.first && current.y == end.second) {
            return getPath(current);
        }
        
        visited[current.x][current.y] = true;
        
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            if (isValid(newX, newY, grid) && !visited[newX][newY]) {
                Node neighbor = {newX, newY, current.g + 1, heuristic(newX, newY, end.first, end.second), 0, new Node(current)};
                neighbor.f = neighbor.g + neighbor.h;
                openSet.push(neighbor);
            }
        }
    }
    return {};
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };
    
    pair<int, int> start = {0, 0};
    pair<int, int> end = {2, 2};
    
    vector<pair<int, int>> path = aStar(grid, start, end);
    
    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found: ";
        for (auto p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    return 0;
}
