#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> parent;
vector<int> rank_;

void uf_init(int n) {
    parent.resize(n + 1);
    rank_.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);  // each node is its own parent
    fill(rank_.begin(), rank_.end(), 1);    // rank initialized to 1
}

int uf_find(int u) {
    if (parent[u] != u) {
        parent[u] = uf_find(parent[u]);
    }
    return parent[u];
}

bool uf_union(int u, int v) {
    int root_u = uf_find(u);
    int root_v = uf_find(v);

    if (root_u == root_v) {
        return false;  // cycle detected
    }

    if (rank_[root_u] > rank_[root_v]) {
        parent[root_v] = root_u;
    } else if (rank_[root_u] < rank_[root_v]) {
        parent[root_u] = root_v;
    } else {
        parent[root_v] = root_u;
        rank_[root_u]++;
    }
    return true;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    uf_init(n);

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if (!uf_union(u, v)) {
            return edge;  // redundant edge found
        }
    }
    return {};  
}

int main() {
    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> redundantEdge1 = findRedundantConnection(edges1);
    cout << "Redundant edge in Example 1: [" << redundantEdge1[0] << ", " << redundantEdge1[1] << "]" << endl;

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> redundantEdge2 = findRedundantConnection(edges2);
    cout << "Redundant edge in Example 2: [" << redundantEdge2[0] << ", " << redundantEdge2[1] << "]" << endl;

    vector<vector<int>> edges3 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> redundantEdge3 = findRedundantConnection(edges3);
    cout << "Redundant edge in Example 3: [" << redundantEdge3[0] << ", " << redundantEdge3[1] << "]" << endl;

    return 0;
}
