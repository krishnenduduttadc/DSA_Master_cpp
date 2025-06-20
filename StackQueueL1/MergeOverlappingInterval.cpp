#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Pair {
    int st;
    int et;
    
    Pair(int s, int e) {
        st = s;
        et = e;
    }
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.st < b.st;
}

void mergeOverlappingIntervals(vector<Pair>& intervals) {
    sort(intervals.begin(), intervals.end(), comparePairs);

    stack<Pair> st;
    st.push(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        Pair top = st.top();
        
        if (intervals[i].st <= top.et) {
            top.et = max(top.et, intervals[i].et);
            st.pop();
            st.push(top);
        } else {
            st.push(intervals[i]);
        }
    }
    
    stack<Pair> result;
    while (!st.empty()) {
        result.push(st.top());
        st.pop();
    }
    
    while (!result.empty()) {
        Pair p = result.top();
        cout << p.st << " " << p.et << endl;
        result.pop();
    }
}

int main() {
    vector<Pair> intervals = {
        {22, 28},
        {1, 8},
        {25, 27},
        {14, 19},
        {27, 30},
        {5, 12}
    };
    
    mergeOverlappingIntervals(intervals);
    return 0;
}
