#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Kosaraju {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfsTranspose(int node, vector<int>& vis, vector<vector<int>>& adjT) {
        vis[node] = 1;
        for (int it : adjT[node]) {
            if (!vis[it]) {
                dfsTranspose(it, vis, adjT);
            }
        }
    }

public:
    // Function to find the number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Perform DFS and fill the stack.
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Create the transposed graph.
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (int it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 3: Count SCCs using DFS on the transposed graph.
        int sccCount = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                sccCount++;
                dfsTranspose(node, vis, adjT);
            }
        }

        return sccCount;
    }
};

int main() {
    int n = 5;
    int edges[][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<vector<int>> adj(n);
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Kosaraju obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
