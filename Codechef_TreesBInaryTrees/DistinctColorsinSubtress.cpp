#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list for the tree
vector<int> colors; // Store colors of nodes
vector<int> distinctColorCount; // Result array to hold distinct color counts
vector<set<int>> subtreeColors; // To track colors in each subtree

void dfs(int node, int parent) {
    subtreeColors[node].insert(colors[node]); // Add current node's color to its set

    for (int neighbor : adj[node]) {
        if (neighbor != parent) { // Avoid going back to the parent
            dfs(neighbor, node); // Recur for the child
            // Merge sets, keeping the larger one to minimize insertions
            if (subtreeColors[neighbor].size() > subtreeColors[node].size()) {
                swap(subtreeColors[neighbor], subtreeColors[node]);
            }
            // Insert colors from the child's set into the current node's set
            subtreeColors[node].insert(subtreeColors[neighbor].begin(), subtreeColors[neighbor].end());
        }
    }
    
    // The size of the subtreeColors set will give us distinct colors in the subtree
    distinctColorCount[node] = subtreeColors[node].size();
}

int main() {
    int n;
    cin >> n; // Read the number of nodes

    // Read the colors of the nodes
    colors.resize(n + 1); // Using 1-based indexing
    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    // Initialize the adjacency list
    adj.resize(n + 1); // Using 1-based indexing

    // Read the edges and build the tree
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize the result array
    distinctColorCount.resize(n + 1, 0);
    subtreeColors.resize(n + 1); // To track colors in each subtree
    
    // Start DFS from the root node (1)
    dfs(1, -1); // Start DFS with node 1 and no parent (-1)

    // Print the results for each node
    for (int i = 1; i <= n; i++) {
        cout << distinctColorCount[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
7
1 2 3 4 3 4 5
1 2
1 7
1 5
2 4
2 3
5 6

*/