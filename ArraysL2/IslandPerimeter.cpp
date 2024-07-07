#include <iostream>
#include <vector>
using namespace std;

int perimeter(vector<vector<int>>& grid) {
    int p = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                p += 4;

                if (i > 0 && grid[i - 1][j] == 1) {
                    p -= 2;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    p -= 2;
                }
            }
        }
    }
    return p;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0},
        {1, 1, 1},
        {0, 1, 0},
        {0, 1, 0}
    };
    
    int p = perimeter(grid);
    cout << p << endl;

    return 0;
}
