#include <iostream>
#include <vector>

using namespace std;

class NumberofIslandsII {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    NumberofIslandsII(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        int ulp = findUPar(parent[node]);
        parent[node] = ulp;
        return parent[node];
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
};

bool isValid(int adjr, int adjc, int n, int m) {
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    NumberofIslandsII ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> ans;
    int cnt = 0;

    int len = operators.size();
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    for (int i = 0; i < len; i++) {
        int row = operators[i][0];
        int col = operators[i][1];

        if (vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        for (int ind = 0; ind < 4; ind++) {
            int adjr = row + dr[ind];
            int adjc = col + dc[ind];

            if (isValid(adjr, adjc, n, m) && vis[adjr][adjc] == 1) {
                int nodeNo = row * m + col;
                int adjNodeNo = adjr * m + adjc;

                if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                    cnt--;
                    ds.unionBySize(nodeNo, adjNodeNo);
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
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    vector<int> ans = numOfIslands(n, m, operators);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
