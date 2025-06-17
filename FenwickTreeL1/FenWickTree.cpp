#include <iostream>
#include <vector>
using namespace std;

// Global Fenwick Tree and size
vector<int> fenwick;
int n;

// Initialize Fenwick Tree
void initFenwick(int size) {
    n = size + 1;
    fenwick.assign(n, 0);
}

// Add value to index
void add(int idx, int val) {
    idx++; // Convert to 1-based indexing
    while (idx < n) {
        fenwick[idx] += val;
        idx += idx & (-idx); // Add last set bit
    }
}

// Get prefix sum up to index
int sum(int idx) {
    idx++; // Convert to 1-based indexing
    int ans = 0;
    while (idx > 0) {
        ans += fenwick[idx];
        idx -= idx & (-idx); // Remove last set bit
    }
    return ans;
}

// Get range sum [l, r]
int rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    initFenwick(v.size());

    // Initialize Fenwick Tree
    for (int i = 0; i < v.size(); i++) {
        add(i, v[i]);
    }

    // Query range sum [3, 5]
    cout << rangeSum(3, 5) << endl; // Output: 15

    // Update index 4 with new value -3
    add(4, -3);

    // Query range sum [3, 5] after update
    cout << rangeSum(3, 5) << endl; // Output: 12

    return 0;
}
