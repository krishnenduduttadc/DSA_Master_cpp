#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// Function to perform DFS and calculate the sum of all branch values
long long dfs(vector<vector<int>>& g, vector<int>& a, int node, long long cur, vector<bool>& vis) {
    vis[node] = true;
    cur = (cur * 10 + a[node]) % MOD;
    
    long long totalSum = 0;
    bool isLeaf = true;

    for (int child : g[node]) {
        if (!vis[child]) {
            isLeaf = false;
            totalSum = (totalSum + dfs(g, a, child, cur, vis)) % MOD;
        }
    }
    
    if (isLeaf) {
        return cur; // If it's a leaf node, return the current value
    }
    return totalSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        long long totalBranchSum = dfs(g, a, 1, 0, vis);
        
        cout << totalBranchSum << '\n';
    }

    return 0;
}


/*


*/3
2
9 3
1 2
4
0 3 9 5
1 3
3 4
3 2
3
9 0 2
1 2
1 3
