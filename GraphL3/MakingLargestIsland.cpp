#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankArr, sizeArr;

void makeSet(int n)
{
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);
    sizeArr.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}

int findUPar(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}

void unionBySize(int u, int v)
{
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
        return;
    if (sizeArr[ulp_u] < sizeArr[ulp_v])
    {
        parent[ulp_u] = ulp_v;
        sizeArr[ulp_v] += sizeArr[ulp_u];
    }
    else
    {
        parent[ulp_v] = ulp_u;
        sizeArr[ulp_u] += sizeArr[ulp_v];
    }
}

// ---------- Helper ----------
bool isValid(int newr, int newc, int n)
{
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
}

// ---------- Main Function ----------
int MaxConnection(vector<vector<int>> &grid)
{
    int n = grid.size();
    makeSet(n * n);

    // Step 1: Join all 1s
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNodeNo = newr * n + newc;
                    unionBySize(nodeNo, adjNodeNo);
                }
            }
        }
    }

    // Step 2: Try flipping each 0 and calculate max connection
    int mx = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> components;
            for (int ind = 0; ind < 4; ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if (isValid(newr, newc, n))
                {
                    if (grid[newr][newc] == 1)
                    {
                        components.insert(findUPar(newr * n + newc));
                    }
                }
            }
            int sizeTotal = 0;
            for (auto it : components)
            {
                sizeTotal += sizeArr[it];
            }
            mx = max(mx, sizeTotal + 1);
        }
    }

    // Final check: if all are 1s
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
        mx = max(mx, sizeArr[findUPar(cellNo)]);
    }

    return mx;
}

// ---------- Driver ----------
int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}};

    int ans = MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
    return 0;
}
