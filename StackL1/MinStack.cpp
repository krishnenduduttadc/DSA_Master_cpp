#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {
        minVal = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            minVal = val;
            st.push(0LL);
        } else {
            long long diff = val - minVal;
            st.push(diff);
            if (val < minVal) {
                minVal = val;
            }
        }
    }

    void pop() {
        long long rem = st.top();
        st.pop();
        if (rem < 0) {
            minVal = minVal - rem;
        }
    }

    int top() {
        long long rem = st.top();
        if (rem < 0) {
            return static_cast<int>(minVal);
        } else {
            return static_cast<int>(minVal + rem);
        }
    }

    int getMin() {
        return static_cast<int>(minVal);
    }
};

int main() {
    MinStack minStack;

    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);

    cout << "Minimum value: " << minStack.getMin() << endl; // Should print 0
    minStack.pop();
    cout << "Minimum value: " << minStack.getMin() << endl; // Should print 0
    minStack.pop();
    cout << "Minimum value: " << minStack.getMin() << endl; // Should print 0
    minStack.pop();
    cout << "Minimum value: " << minStack.getMin() << endl; // Should print 2

    return 0;
}
