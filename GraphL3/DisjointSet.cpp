#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        int uPar = findUPar(parent[node]);
        parent[node] = uPar;
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);

        if (uPar == vPar) return;

        if (rank[uPar] < rank[vPar]) {
            parent[uPar] = vPar;
        } else if (rank[vPar] < rank[uPar]) {
            parent[vPar] = uPar;
        } else {
            parent[vPar] = uPar;
            rank[uPar]++;
        }
    }

    void unionBySize(int u, int v) {
        int uPar = findUPar(u);
        int vPar = findUPar(v);

        if (uPar == vPar) return;

        if (size[uPar] < size[vPar]) {
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        } else {
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if 3 and 7 are in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not Same" << endl;
    }

    ds.unionByRank(3, 7);

    // Check again after union
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not Same" << endl;
    }

    return 0;
}
