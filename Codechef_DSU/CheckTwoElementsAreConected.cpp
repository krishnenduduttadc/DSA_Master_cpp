#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int setSize[100000];

int dsuFind(int a) {
    if (parent[a] == a) return a;
    return parent[a] = dsuFind(parent[a]);
}

void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if (leader_a != leader_b) {
        if (setSize[leader_b] < setSize[leader_a]) {
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;
        setSize[leader_a] += setSize[leader_b];
    }
}

int main() {
    // Hardcoded input
    int n = 10; // number of elements
    int m = 4;  // number of connections
    vector<pair<int, int>> connections = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };
    int q = 8; // number of queries
    vector<pair<int, int>> queries = {
        {5, 1},
        {1, 2},
        {2, 3},
        {4, 5},
        {0, 1},
        {0, 9},
        {9, 8},
        {8, 7}
    };

    // Initialize DSU structures
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        setSize[i] = 1;
    }

    // Perform unions
    for (const auto& connection : connections) {
        dsuUnion(connection.first, connection.second);
    }

    // Process queries
    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        if (dsuFind(x) == dsuFind(y)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
