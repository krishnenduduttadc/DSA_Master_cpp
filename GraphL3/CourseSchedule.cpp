#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CourseSchedule {
public:
    static vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Create adjacency list and calculate indegrees
        for (int i = 0; i < m; ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        // Initialize queue for nodes with zero indegree
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

            // Decrease indegree of adjacent nodes and push them to queue if indegree becomes zero
            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If processed nodes count is equal to total nodes, return topological order
        if (count == n) {
            return topo;
        } else {
            return {}; // Return empty array if there's a cycle (i.e., count != n)
        }
    }
};

int main() {
    int N = 4;
    int M = 3;
    vector<vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};

    vector<int> ans = CourseSchedule::findOrder(N, M, prerequisites);

    for (int task : ans) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
