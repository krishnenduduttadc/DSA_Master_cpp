#include <iostream>
#include <stack>
#include <climits>
using namespace std;

struct MinStack {
    stack<long long> st;
    long long minVal;
};

// Initialize the MinStack
void init(MinStack &ms) {
    ms.minVal = INT_MAX;
}

// Push value to MinStack
void push(MinStack &ms, int val) {
    if (ms.st.empty()) {
        ms.minVal = val;
        ms.st.push(0LL);
    } else {
        long long diff = val - ms.minVal;
        ms.st.push(diff);
        if (val < ms.minVal) {
            ms.minVal = val;
        }
    }
}

// Pop the top value
void pop(MinStack &ms) {
    if (ms.st.empty()) return;

    long long rem = ms.st.top();
    ms.st.pop();
    if (rem < 0) {
        ms.minVal = ms.minVal - rem;
    }
}

// Return the top value
int top(MinStack &ms) {
    long long rem = ms.st.top();
    if (rem < 0) {
        return static_cast<int>(ms.minVal);
    } else {
        return static_cast<int>(ms.minVal + rem);
    }
}

// Return the minimum value
int getMin(MinStack &ms) {
    return static_cast<int>(ms.minVal);
}

// Test in main
int main() {
    MinStack minStack;
    init(minStack);

    push(minStack, 2);
    push(minStack, 0);
    push(minStack, 3);
    push(minStack, 0);

    cout << "Minimum value: " << getMin(minStack) << endl; // 0
    pop(minStack);
    cout << "Minimum value: " << getMin(minStack) << endl; // 0
    pop(minStack);
    cout << "Minimum value: " << getMin(minStack) << endl; // 0
    pop(minStack);
    cout << "Minimum value: " << getMin(minStack) << endl; // 2

    return 0;
}
