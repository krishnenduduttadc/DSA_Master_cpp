#include <bits/stdc++.h>
using namespace std;

vector<int> rankArr, parent, sizeArr;

void initDisjointSet(int n)
{
    rankArr.resize(n + 1, 0);
    parent.resize(n + 1);
    sizeArr.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        sizeArr[i] = 1;
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

int Solve(int n, vector<vector<int>> &edge)
{
    initDisjointSet(n);
    int cntExtras = 0;
    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];
        if (findUPar(u) == findUPar(v))
        {
            cntExtras++;
        }
        else
        {
            unionBySize(u, v);
        }
    }
    int cntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            cntC++;
    }
    int ans = cntC - 1;
    if (cntExtras >= ans)
        return ans;
    return -1;
}

int main()
{
    int V = 9;
    vector<vector<int>> edge = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    int ans = Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;
}
