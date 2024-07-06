#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    // Calculate indegree for each vertex
    for (int i = 0; i < V; ++i) {
        for (int it : adj[i]) {
            indegree[it]++;
        }
    }

    // Queue to store vertices with zero indegree
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        ++count;

        // Reduce indegree of adjacent nodes
        for (int it : adj[node]) {
            if (--indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Check if there was a cycle
    if (count != V) {
        // Graph contains a cycle
        return vector<int>(); // Returning empty vector to indicate cycle
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

    if (ans.empty()) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Topological order: ";
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
