#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> fenwick;
    int n;

public:
    FenwickTree(int size) {
        n = size + 1;
        fenwick.assign(n, 0);
    }

    void add(int idx, int val) {
        idx++; // 1 based index
        while (idx < n) {
            fenwick[idx] += val;
            idx += idx & (-idx); // add last set bit
        }
    }

    int sum(int idx) {
        idx++; // 1 based index
        int ans = 0;
        while (idx > 0) {
            ans += fenwick[idx];
            idx -= idx & (-idx); // remove last set bit
        }
        return ans;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    FenwickTree tree(v.size());

    // Initialize Fenwick Tree
    for (int i = 0; i < v.size(); i++) {
        tree.add(i, v[i]);
    }

    // Query range sum [3, 5]
    cout << tree.rangeSum(3, 5) << endl; // Output: 15

    // Update index 4 with new value -3
    tree.add(4, -3);

    // Query range sum [3, 5] after update
    cout << tree.rangeSum(3, 5) << endl; // Output: 12

    return 0;
}
