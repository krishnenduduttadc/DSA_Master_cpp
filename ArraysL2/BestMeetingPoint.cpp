#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minTotalDistance(vector<vector<int>>& grid) {
    // Collect x-coordinates and y-coordinates of all 1s in the grid
    vector<int> xcord, ycord;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                xcord.push_back(r);
                ycord.push_back(c);
            }
        }
    }

    // Find median point (x, y)
    int x = xcord[xcord.size() / 2];
    int y = ycord[ycord.size() / 2];

    // Calculate Manhattan distance
    int dist = 0;
    for (int xval : xcord) {
        dist += abs(x - xval);
    }
    for (int yval : ycord) {
        dist += abs(y - yval);
    }

    return dist;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int dist = minTotalDistance(grid);
    cout << dist << endl; // Output should be 8

    return 0;
}
