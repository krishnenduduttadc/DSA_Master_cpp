#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> st;

public:
    void init(int _n) {
        n = _n;
        st.assign(4 * n, 0); // Initialize segment tree with size 4*n
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
        if (start > r || end < l) {
            return 0;
        }

        if (start >= l && end <= r) {
            return st[node];
        }

        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);

        return q1 + q2;
    }

    void update(int start, int end, int node, int index, int value) {
        if (start == end) {
            st[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        } else {
            update(mid + 1, end, 2 * node + 2, index, value);
        }

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int>& v) {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        update(0, n - 1, 0, x, y);
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    SegmentTree tree;
    tree.init(v.size());
    tree.build(v);

    cout << tree.query(0, 4) << endl;
    tree.update(4, 10);
    cout << tree.query(0, 4) << endl;

    tree.update(2, 20);
    cout << tree.query(0, 4) << endl;

    return 0;
}
