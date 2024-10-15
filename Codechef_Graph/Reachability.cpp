#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
vector<int> adj[N];
vector<bool> vis(N, 0);

void dfs(int v) {
    if(vis[v]) {
        return;
    }
    vis[v] = true;

    for(auto u: adj[v]) {
        dfs(u);
    }
}

int main() {
    int n, m; 
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Directed edge
    }

    dfs(1); // Start dfs from source: 1

    for(int i = 1; i <= n; i++) {
        if(vis[i]) // A node is reachable if it is marked visited
            cout << i << " ";
    }

    return 0;
}


/*
5 6
1 3
4 3
3 2
2 4
5 4
3 1

*/