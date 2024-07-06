#include <iostream>
#include <vector>
using namespace std;

class NoofOperationsToNetworkConnected {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    NoofOperationsToNetworkConnected(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
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

    int solve(int n, vector<vector<int>>& edges) {
        int cntExtras = 0;
        int m = edges.size();

        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (findUPar(u) == findUPar(v)) {
                cntExtras++;
            } else {
                unionBySize(u, v);
            }
        }

        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) cntC++;
        }

        int ans = cntC - 1;

        if (cntExtras >= ans) return ans;
        return -1;
    }
};

int main() {
    int V = 9;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    NoofOperationsToNetworkConnected obj(V);
    int ans = obj.solve(V, edges);

    cout << "The number of operations needed: " << ans << endl;

    return 0;
}
