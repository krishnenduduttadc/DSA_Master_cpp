#include <bits/stdc++.h>
using namespace std;

vector<int> parent, size;

void makeSet(int n) {
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int findUPar(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findUPar(parent[node]);
}

void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;
    if (size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    } else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

bool isValid(int row, int col, int n, int m) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    makeSet(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    vector<int> ans;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (auto it : operators) {
        int row = it[0], col = it[1];

        if (vis[row][col]) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        int nodeNo = row * m + col;

        for (int i = 0; i < 4; i++) {
            int adjr = row + dr[i];
            int adjc = col + dc[i];

            if (isValid(adjr, adjc, n, m) && vis[adjr][adjc]) {
                int adjNodeNo = adjr * m + adjc;
                if (findUPar(nodeNo) != findUPar(adjNodeNo)) {
                    unionBySize(nodeNo, adjNodeNo);
                    cnt--;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2},
        {1, 2}, {0, 2}
    };

    vector<int> res = numOfIslands(n, m, operators);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
