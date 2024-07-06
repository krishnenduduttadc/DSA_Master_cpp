#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unionSets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (size[root_u] < size[root_v]) {
                swap(root_u, root_v);
            }
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }

    int getSize(int node) {
        return size[find(node)];
    }
};

class MakingaLargeIsland {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union adjacent 1s in the grid
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    for (int ind = 0; ind < 4; ++ind) {
                        int newr = row + dr[ind];
                        int newc = col + dc[ind];
                        if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                            int nodeNo = row * n + col;
                            int adjNodeNo = newr * n + newc;
                            ds.unionSets(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the largest group size
        int max_size = 0;
        unordered_set<int> components;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    components.clear();
                    for (int ind = 0; ind < 4; ++ind) {
                        int newr = row + dr[ind];
                        int newc = col + dc[ind];
                        if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                            components.insert(ds.find(newr * n + newc));
                        }
                    }
                    int sizeTotal = 1; // Include the current cell as '1'
                    for (int parent : components) {
                        sizeTotal += ds.getSize(parent);
                    }
                    max_size = max(max_size, sizeTotal);
                }
            }
        }

        // Step 3: Check the size of each individual set
        for (int cellNo = 0; cellNo < n * n; ++cellNo) {
            if (grid[cellNo / n][cellNo % n] == 1) {
                max_size = max(max_size, ds.getSize(cellNo));
            }
        }

        return max_size;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0}
    };

    MakingaLargeIsland obj;
    int ans = obj.MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;

    return 0;
}
