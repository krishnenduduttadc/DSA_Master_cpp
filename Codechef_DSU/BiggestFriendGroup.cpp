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
        parent[leader_a] = leader_b;
        setSize[leader_b] += setSize[leader_a];
    }
}

int main() {
    // Hardcoded input
    int n = 10; // number of elements
    int m = 5;  // number of connections
    vector<pair<int, int>> connections = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        setSize[i] = 1;
    }

    for (const auto& connection : connections) {
        dsuUnion(connection.first, connection.second);
    }

    int leadersSize[100] = {0};

    for (int i = 0; i < n; i++) {
        leadersSize[dsuFind(i)]++;
    }

    int maxSize = 0;
    for (int i = 0; i < n; i++) {
        if (leadersSize[i] > maxSize) {
            maxSize = leadersSize[i];
        }
    }

    cout << maxSize << endl;

    return 0;
}
