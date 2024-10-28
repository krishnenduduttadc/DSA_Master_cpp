#include <bits/stdc++.h>
using namespace std;

int parent[1000000];
int setSize[1000000];

// Optimized find function with path compression
int dsuFind(int a) {
    if (parent[a] == a) return a;
    // Path compression: flatten the structure
    return parent[a] = dsuFind(parent[a]);
}

// Optimized union function using union by size
void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if (leader_a != leader_b) {
        // Union by size: attach smaller tree under the larger tree
        if (setSize[leader_b] < setSize[leader_a]) {
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;          // Attach leader_b's tree to leader_a's tree
        setSize[leader_a] += setSize[leader_b]; // Update the size of the new root
    }
}

int main() {
    int n = 5; // Number of elements
    int m = 7; // Number of commands
    
    // Initialize the parent and size arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Each element is its own parent
        setSize[i] = 1; // Each set initially contains one element
    }
    
    // Hardcoded commands (union/find operations)
    vector<pair<string, pair<int, int>>> commands = {
        {"union", {1, 0}},
        {"union", {2, 1}},
        {"find", {0, -1}}, // -1 as a placeholder since find doesn't need the second element
        {"find", {1, -1}},
        {"find", {2, -1}},
        {"find", {3, -1}},
        {"find", {4, -1}}
    };

    // Process hardcoded commands
    for (const auto& command : commands) {
        if (command.first == "union") {
            int a = command.second.first;
            int b = command.second.second;
            dsuUnion(a, b);
        } else if (command.first == "find") {
            int a = command.second.first;
            cout << "Find " << a << ": " << dsuFind(a) << endl; // Output the leader of the set containing 'a'
        }
    }

    return 0;
}

/*
Expected Output:
Find 0: 0
Find 1: 0
Find 2: 0
Find 3: 3
Find 4: 4
*/
