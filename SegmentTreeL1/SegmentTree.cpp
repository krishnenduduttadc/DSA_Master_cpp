#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5; // Adjust size as needed
vector<int> st(4 * MAXN);
int n;

// Build the segment tree
void build(int start, int end, int node, const vector<int>& v) {
    if (start == end) {
        st[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1, v);
    build(mid + 1, end, 2 * node + 2, v);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

// Range query: sum from l to r
int query(int start, int end, int l, int r, int node) {
    if (start > r || end < l)
        return 0;

    if (start >= l && end <= r)
        return st[node];

    int mid = (start + end) / 2;
    int q1 = query(start, mid, l, r, 2 * node + 1);
    int q2 = query(mid + 1, end, l, r, 2 * node + 2);

    return q1 + q2;
}

// Point update: update index with new value
void update(int start, int end, int node, int index, int value) {
    if (start == end) {
        st[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid)
        update(start, mid, 2 * node + 1, index, value);
    else
        update(mid + 1, end, 2 * node + 2, index, value);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    n = v.size();

    build(0, n - 1, 0, v);

    cout << query(0, n - 1, 0, 4, 0) << endl; // Sum from index 0 to 4

    update(0, n - 1, 0, 4, 10); // Set index 4 to 10
    cout << query(0, n - 1, 0, 4, 0) << endl;

    update(0, n - 1, 0, 2, 20); // Set index 2 to 20
    cout << query(0, n - 1, 0, 4, 0) << endl;

    return 0;
}
