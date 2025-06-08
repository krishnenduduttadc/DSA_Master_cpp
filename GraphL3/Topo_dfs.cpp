#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
    vis[node] = 1; // Mark node as visited

    for (int it : adj[node]) {
        if (vis[it] == 0) { // If adjacent node is not visited, perform DFS on it
            dfs(it, vis, st, adj);
        }
    }

    st.push(node); // Push current node to stack after visiting all its dependencies
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0); // Initialize visited array
    stack<int> st; // Stack to store nodes in topological order

    for (int i = 0; i < V; ++i) {
        if (vis[i] == 0) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> topo(V);
    int index = 0;

    while (!st.empty()) {
        topo[index++] = st.top();
        st.pop();
    }

    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    vector<int> ans = topoSort(V, adj);

    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
