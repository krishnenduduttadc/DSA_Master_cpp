#include <bits/stdc++.h>
using namespace std;

int parent[100000];

// Path compression in the find function
int dsuFind(int a) {
    if (parent[a] == a) return a;
    // Path compression
    return parent[a] = dsuFind(parent[a]);
}

// Union by rank is not implemented for simplicity in this example
void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if (leader_a != leader_b) {
        parent[leader_b] = leader_a; // Union the sets
    }
}

int main() {
    // Hardcoded input
    int n = 5; // Number of elements
    int m = 7; // Number of operations

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is its own parent
    }

    // Hardcoded operations
    vector<pair<string, pair<int, int>>> operations = {
        {"union", {1, 0}},
        {"union", {2, 1}},
        {"find", {0, -1}}, // -1 is a placeholder since we don't need a second argument for find
        {"find", {1, -1}},
        {"find", {2, -1}},
        {"find", {3, -1}},
        {"find", {4, -1}}
    };

    // Process operations
    for (const auto& op : operations) {
        string command = op.first;
        int a = op.second.first;
        if (command == "union") {
            int b = op.second.second;
            dsuUnion(a, b);
        } else if (command == "find") {
            cout << "Find " << a << ": " << dsuFind(a) << endl;
        }
    }

    return 0;
}
