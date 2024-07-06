#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
    int li;   // List index
    int di;   // Data index (current index in the list)
    int val;  // Value at current index in the list

    Pair(int li, int di, int val) : li(li), di(di), val(val) {}

    bool operator>(const Pair& other) const {
        return val > other.val;
    }
};

vector<int> mergeKSortedLists(vector<vector<int>>& lists) {
    vector<int> rv;

    // Min-heap priority queue
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    
    // Initialize the priority queue with the first element from each list
    for (int i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            pq.push(Pair(i, 0, lists[i][0]));
        }
    }

    while (!pq.empty()) {
        Pair p = pq.top();
        pq.pop();

        // Add the current value to result vector
        rv.push_back(p.val);

        // Move to the next element in the same list
        p.di++;
        if (p.di < lists[p.li].size()) {
            p.val = lists[p.li][p.di];
            pq.push(p);
        }
    }

    return rv;
}

int main() {
    vector<vector<int>> lists = {
        {10, 20, 30, 40, 50},
        {5, 7, 9, 11, 19, 55, 57},
        {1, 2, 3}
    };

    vector<int> mlist = mergeKSortedLists(lists);

    for (int val : mlist) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
