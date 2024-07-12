#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent
        rank.assign(n + 1, 1); // Initialize rank of each node as 1
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) {
            return false; // They are already in the same set (cycle detected)
        }

        // Union by rank
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            if (!uf.unionSets(u, v)) {
                return edge; // Return the redundant edge
            }
        }

        return vector<int>(); // Should not reach here for valid input
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> redundantEdge1 = solution.findRedundantConnection(edges1);
    cout << "Redundant edge in Example 1: [" << redundantEdge1[0] << ", " << redundantEdge1[1] << "]" << endl;

    // Example 2
    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> redundantEdge2 = solution.findRedundantConnection(edges2);
    cout << "Redundant edge in Example 2: [" << redundantEdge2[0] << ", " << redundantEdge2[1] << "]" << endl;

    // Example 3
    vector<vector<int>> edges3 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> redundantEdge3 = solution.findRedundantConnection(edges3);
    cout << "Redundant edge in Example 3: [" << redundantEdge3[0] << ", " << redundantEdge3[1] << "]" << endl;

    return 0;
}
