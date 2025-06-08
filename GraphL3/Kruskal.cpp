#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankArr, sizeArr;

void makeSet(int n) {
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);
    sizeArr.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int findUPar(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}

void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;

    if (rankArr[ulp_u] < rankArr[ulp_v]) {
        parent[ulp_u] = ulp_v;
    }
    else if (rankArr[ulp_v] < rankArr[ulp_u]) {
        parent[ulp_v] = ulp_u;
    }
    else {
        parent[ulp_v] = ulp_u;
        rankArr[ulp_u]++;
    }
}

void unionBySize(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;

    if (sizeArr[ulp_u] < sizeArr[ulp_v]) {
        parent[ulp_u] = ulp_v;
        sizeArr[ulp_v] += sizeArr[ulp_u];
    }
    else {
        parent[ulp_v] = ulp_u;
        sizeArr[ulp_u] += sizeArr[ulp_v];
    }
}

// ---------- MST Function ----------
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjNode}});
        }
    }

    makeSet(V);
    sort(edges.begin(), edges.end());

    int mstWt = 0;
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (findUPar(u) != findUPar(v)) {
            mstWt += wt;
            unionBySize(u, v);
        }
    }

    return mstWt;
}

// ---------- Main Function ----------
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}
    };

    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int mstWt = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;

    return 0;
}
