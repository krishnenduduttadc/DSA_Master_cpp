#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Pair {
public:
    int row, col, msf;
    Pair(int row, int col, int msf) : row(row), col(col), msf(msf) {}
    
    bool operator>(const Pair &other) const {
        return msf > other.msf;
    }
};

int swimInRisingWater(vector<vector<int>>& grid) {
    int n = grid.size();
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.emplace(0, 0, grid[0][0]);
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    while (!pq.empty()) {
        Pair rem = pq.top();
        pq.pop();

        if (rem.row == n - 1 && rem.col == n - 1) {
            return rem.msf;
        }

        if (vis[rem.row][rem.col]) {
            continue;
        }

        vis[rem.row][rem.col] = true;

        for (int i = 0; i < 4; ++i) {
            int rowdash = rem.row + dirs[i][0];
            int coldash = rem.col + dirs[i][1];

            if (rowdash < 0 || coldash < 0 || rowdash >= n || coldash >= n || vis[rowdash][coldash]) {
                continue;
            }

            pq.emplace(rowdash, coldash, max(rem.msf, grid[rowdash][coldash]));
        }
    }
    return 0;
}

int main() {
    // Hardcoded input
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    cout << swimInRisingWater(grid) << endl;
    return 0;
}
