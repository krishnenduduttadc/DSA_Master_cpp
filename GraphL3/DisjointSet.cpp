#include <bits/stdc++.h>
using namespace std;

vector<int> parent, rankVec; // Renamed rank to rankVec

void makeSet(int n) {
    parent.resize(n + 1);
    rankVec.resize(n + 1, 0); // Use rankVec here
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
    int ulp_u = findUPar(u); // ultimate parent of u
    int ulp_v = findUPar(v); // ultimate parent of v
    if (ulp_u == ulp_v) return; // already in the same set

    // Union by rank
    if (rankVec[ulp_u] < rankVec[ulp_v]) { // Use rankVec here
        parent[ulp_u] = ulp_v;
    }
    else if (rankVec[ulp_u] > rankVec[ulp_v]) { // Use rankVec here
        parent[ulp_v] = ulp_u;
    }
    else {
        parent[ulp_v] = ulp_u;
        rankVec[ulp_u]++; // Use rankVec here
    }
}

int main() {
    int n = 7; // Number of elements
    makeSet(n);

    unionByRank(1, 2);
    unionByRank(2, 3);
    unionByRank(4, 5);
    unionByRank(6, 7);
    unionByRank(5, 6);

    // Check if 3 and 7 are in the same set
    if (findUPar(3) == findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }

    unionByRank(3, 7);

    // Check again if 3 and 7 are in the same set
    if (findUPar(3) == findUPar(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }

    return 0;
}
