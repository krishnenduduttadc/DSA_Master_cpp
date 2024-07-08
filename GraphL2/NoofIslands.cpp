#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) {
        parent.resize(size, -1);
        rank.resize(size, 1);
    }

    int find(int x) {
        if (parent[x] == -1) {
            parent[x] = x;
            return x;
        }
        if (parent[x] == x) {
            return x;
        }
        int root = find(parent[x]);
        parent[x] = root;
        return root;
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    vector<int> ans;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    UnionFind uf(m * n);
    int count = 0;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (auto& pos : positions) {
        int row = pos[0];
        int col = pos[1];

        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            count++;

            for (auto& dir : dirs) {
                int r = row + dir[0];
                int c = col + dir[1];

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    uf.unionSets(row * n + col, r * n + c);
                }
            }
        }

        ans.push_back(count);
    }

    return ans;
}

int main() {
    int m = 3, n = 3;
    vector<vector<int>> positions = {
        {0, 0},
        {0, 1},
        {1, 2},
        {2, 1}
    };

    vector<int> result = numIslands2(m, n, positions);
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
