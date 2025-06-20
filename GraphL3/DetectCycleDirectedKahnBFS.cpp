#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
    int indegree[V] = {0};

    for (int i = 0; i < V; i++) {
        for (auto node : adj[i]) {
            indegree[node]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;

        for (auto node : adj[curr]) {
            indegree[node]--;
            if (indegree[node] == 0) {
                q.push(node);
            }
        }
    }

    return count != V;  // True if cycle exists, else False
}

int main() {
    int V = 6;
    vector<int> adj[6] = {
        {},     // 0
        {2},    // 1
        {3},    // 2
        {4, 5}, // 3
        {2},    // 4
        {}      // 5
    };

    bool hasCycle = isCyclic(V, adj);
    cout << (hasCycle ? "True" : "False") << endl;

    return 0;
}
