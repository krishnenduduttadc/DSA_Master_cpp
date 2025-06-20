#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (int i = 0; i < m; ++i) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo; // Resulting topological order
    int count = 0;    // Counter to track processed nodes

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node); // Add node to the topological order
        ++count;

        for (int neighbor : adj[node]) {
            if (--indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (count == n) {
        return topo;
    } else {
        return {}; // Return empty array if there's a cycle (i.e., count != n)
    }
}

int main() {
    int N = 4;
    int M = 3;
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};

    vector<int> ans = findOrder(N, M, prerequisites);

    for (int task : ans) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
