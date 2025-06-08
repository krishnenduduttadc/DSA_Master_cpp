#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Step 1: First DFS to fill stack based on finishing times
void dfs1(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs1(neighbor, vis, adj, st);
        }
    }
    st.push(node);
}

// Step 2: DFS on transposed graph
void dfs2(int node, vector<int> &vis, vector<int> adjT[]) {
    vis[node] = 1;
    for (int neighbor : adjT[node]) {
        if (!vis[neighbor]) {
            dfs2(neighbor, vis, adjT);
        }
    }
}

// Main Kosaraju algorithm function
int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    // Step 1: Fill stack with nodes in order of finishing times
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs1(i, vis, adj, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            adjT[neighbor].push_back(i);
        }
    }

    // Step 3: Process all nodes in order defined by the stack
    fill(vis.begin(), vis.end(), 0);
    int scc = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }

    return scc;
}

int main() {
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    int result = kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << result << endl;

    return 0;
}
