#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Pair
{
public:
    int row, col;
    Pair(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int i, int j, vector<vector<int>> &A, queue<Pair> &q, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    q.push(Pair(i, j));
    for (int k = 0; k < 4; ++k)
    {
        int rowdash = i + dirs[k][0];
        int coldash = j + dirs[k][1];

        if (rowdash < 0 || coldash < 0 || coldash >= A[0].size() || rowdash >= A.size() ||
            vis[rowdash][coldash] || A[rowdash][coldash] == 0)
        {
            continue;
        }

        dfs(rowdash, coldash, A, q, vis);
    }
}

int shortestBridge(vector<vector<int>> &A)
{
    queue<Pair> q;
    vector<vector<bool>> visited(A.size(), vector<bool>(A[0].size(), false));
    bool flag = false;

    for (int i = 0; i < A.size() && !flag; ++i)
    {
        for (int j = 0; j < A[0].size() && !flag; ++j)
        {
            if (A[i][j] == 1)
            {
                dfs(i, j, A, q, visited);
                flag = true;
            }
        }
    }

    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size-- > 0)
        {
            Pair rem = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int rowdash = rem.row + dirs[i][0];
                int coldash = rem.col + dirs[i][1];

                if (rowdash < 0 || coldash < 0 || coldash >= A[0].size() || rowdash >= A.size() ||
                    visited[rowdash][coldash])
                {
                    continue;
                }

                if (A[rowdash][coldash] == 1)
                {
                    return level;
                }

                q.push(Pair(rowdash, coldash));
                visited[rowdash][coldash] = true;
            }
        }
        ++level;
    }
    return -1;
}

int main()
{
    // Hardcoded input
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 1}};

    cout << shortestBridge(arr) << endl;

    return 0;
}
