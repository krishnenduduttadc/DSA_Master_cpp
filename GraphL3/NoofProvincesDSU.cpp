#include <iostream>
#include <vector>

using namespace std;

// DSU Helper Functions
int findParent(int node, vector<int>& parent) {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node], parent);  // Path compression
}

void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu == pv) return;

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pv] < rank[pu]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        rank[pv]++;
    }
}

// Main function to count number of provinces
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initialize each node as its own parent
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Union connected nodes
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j] == 1) {
                unionByRank(i, j, parent, rank);
            }
        }
    }

    // Count distinct parents (i.e., provinces)
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) count++;
    }
    return count;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int provinces = findCircleNum(isConnected);
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}
