#include <bits/stdc++.h>
using namespace std;

vector<int> parent, size;

void makeSet(int n)
{
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
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
    if (size[ulp_u] < size[ulp_v])
    {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else
    {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

int maxRemove(vector<vector<int>> &stones, int n)
{
    int maxRow = 0, maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    int totalSize = maxRow + maxCol + 1;
    makeSet(totalSize);

    unordered_map<int, int> stoneNodes;

    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes)
    {
        if (findUPar(it.first) == it.first)
        {
            cnt++;
        }
    }
    return n - cnt;
}

int main()
{
    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};

    int ans = maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}
