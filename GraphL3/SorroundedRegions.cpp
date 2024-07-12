#include <iostream>
#include <vector>
using namespace std;

class SorroundedRegions {
public:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat, vector<int>& delrow, vector<int>& delcol) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        // check for top, right, bottom, left
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and unvisited Os
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse first row and last row
        for (int j = 0; j < m; j++) {
            // check for unvisited Os in the boundary rows
            // first row
            if (vis[0][j] == 0 && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol);
            }

            // last row
            if (vis[n-1][j] == 0 && mat[n-1][j] == 'O') {
                dfs(n-1, j, vis, mat, delrow, delcol);
            }
        }

        // traverse first column and last column
        for (int i = 0; i < n; i++) {
            // check for unvisited Os in the boundary columns
            // first column
            if (vis[i][0] == 0 && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol);
            }

            // last column
            if (vis[i][m-1] == 0 && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat, delrow, delcol);
            }
        }

        // if unvisited O then convert to X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    // n = 5, m = 4
    SorroundedRegions ob;
    vector<vector<char>> ans = ob.fill(5, 4, mat);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
