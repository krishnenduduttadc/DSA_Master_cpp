#include <iostream>
#include <vector>
using namespace std;

vector<int> st, lazy;
int n;

void init(int _n) {
    n = _n;
    st.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
}

void build(int start, int end, int node, vector<int>& v) {
    if (start == end) {
        st[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;
    build(start, mid, 2 * node + 1, v);
    build(mid + 1, end, 2 * node + 2, v);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int query(int start, int end, int l, int r, int node) {
    if (lazy[node] != 0) {
        st[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l)
        return 0;

    if (start >= l && end <= r)
        return st[node];

    int mid = (start + end) / 2;
    int q1 = query(start, mid, l, r, 2 * node + 1);
    int q2 = query(mid + 1, end, l, r, 2 * node + 2);

    return q1 + q2;
}

void update(int start, int end, int l, int r, int node, int value) {
    if (lazy[node] != 0) {
        st[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l)
        return;

    if (start >= l && end <= r) {
        st[node] += value * (end - start + 1);
        if (start != end) {
            lazy[2 * node + 1] += value;
            lazy[2 * node + 2] += value;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, l, r, 2 * node + 1, value);
    update(mid + 1, end, l, r, 2 * node + 2, value);

    st[node] = st[2 * node + 1] + st[2 * node + 2];
}

void build(vector<int>& v) {
    build(0, n - 1, 0, v);
}

int query(int l, int r) {
    return query(0, n - 1, l, r, 0);
}

void update(int l, int r, int x) {
    update(0, n - 1, l, r, 0, x);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    init(v.size());
    build(v);
    cout << query(0, 4) << endl;   // Should print 1+2+3+4+5 = 15
    update(0, 1, 10);              // Add 10 to indices 0 and 1
    cout << query(0, 4) << endl;   // Now 11+12+3+4+5 = 35
    return 0;
}
