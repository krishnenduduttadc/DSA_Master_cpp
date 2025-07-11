#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int i, int j, vector<vector<int>> &A, queue<pair<int, int>> &q, vector<vector<bool>> &vis) {
    vis[i][j] = true;
    q.push(make_pair(i, j));

    for (int k = 0; k < 4; ++k) {
        int rowdash = i + dirs[k][0];
        int coldash = j + dirs[k][1];

        if (rowdash < 0 || coldash < 0 || rowdash >= A.size() || coldash >= A[0].size() ||
            vis[rowdash][coldash] || A[rowdash][coldash] == 0) {
            continue;
        }

        dfs(rowdash, coldash, A, q, vis);
    }
}

int shortestBridge(vector<vector<int>> &A) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    bool flag = false;

    for (int i = 0; i < A.size() && !flag; ++i) {
        for (int j = 0; j < A[0].size() && !flag; ++j) {
            if (A[i][j] == 1) {
                dfs(i, j, A, q, visited);
                flag = true;
            }
        }
    }

    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            pair<int, int> rem = q.front();
            q.pop();
            int row = rem.first;
            int col = rem.second;

            for (int i = 0; i < 4; ++i) {
                int rowdash = row + dirs[i][0];
                int coldash = col + dirs[i][1];

                if (rowdash < 0 || coldash < 0 || rowdash >= A.size() || coldash >= A[0].size() ||
                    visited[rowdash][coldash]) {
                    continue;
                }

                if (A[rowdash][coldash] == 1) {
                    return level;
                }

                q.push(make_pair(rowdash, coldash));
                visited[rowdash][coldash] = true;
            }
        }
        ++level;
    }

    return -1;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 1}
    };

    cout << shortestBridge(arr) << endl;

    return 0;
}
