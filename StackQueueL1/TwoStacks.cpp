#include <iostream>
#include <vector>
using namespace std;

struct TwoStack {
    vector<int> data;
    int tos1; // Top of Stack 1
    int tos2; // Top of Stack 2
};

void initTwoStack(TwoStack& st, int cap) {
    st.data.resize(cap);
    st.tos1 = -1;
    st.tos2 = cap;
}

int size1(const TwoStack& st) {
    return st.tos1 + 1;
}

int size2(const TwoStack& st) {
    return st.data.size() - st.tos2;
}

void push1(TwoStack& st, int val) {
    if (st.tos2 == st.tos1 + 1) {
        cout << "Stack overflow\n";
    } else {
        st.tos1++;
        st.data[st.tos1] = val;
    }
}

void push2(TwoStack& st, int val) {
    if (st.tos2 == st.tos1 + 1) {
        cout << "Stack overflow\n";
    } else {
        st.tos2--;
        st.data[st.tos2] = val;
    }
}

int pop1(TwoStack& st) {
    if (size1(st) == 0) {
        cout << "Stack underflow\n";
        return -1;
    } else {
        int val = st.data[st.tos1];
        st.tos1--;
        return val;
    }
}

int pop2(TwoStack& st) {
    if (size2(st) == 0) {
        cout << "Stack underflow\n";
        return -1;
    } else {
        int val = st.data[st.tos2];
        st.tos2++;
        return val;
    }
}

int top1(const TwoStack& st) {
    if (size1(st) == 0) {
        cout << "Stack underflow\n";
        return -1;
    } else {
        return st.data[st.tos1];
    }
}

int top2(const TwoStack& st) {
    if (size2(st) == 0) {
        cout << "Stack underflow\n";
        return -1;
    } else {
        return st.data[st.tos2];
    }
}

int main() {
    int capacity = 5;
    TwoStack st;
    initTwoStack(st, capacity);

    push1(st, 10);
    push1(st, 20);
    push2(st, 30);
    push2(st, 40);
    push2(st, 50);
    push1(st, 60); // Overflow

    cout << "top1: " << top1(st) << "\n";
    cout << "pop1: " << pop1(st) << "\n";
    cout << "top1: " << top1(st) << "\n";
    cout << "pop1: " << pop1(st) << "\n";
    cout << "top2: " << top2(st) << "\n";
    cout << "pop2: " << pop2(st) << "\n";
    cout << "top2: " << top2(st) << "\n";
    cout << "pop2: " << pop2(st) << "\n";
    cout << "top1: " << top1(st) << "\n";
    cout << "pop1: " << pop1(st) << "\n";
    cout << "top2: " << top2(st) << "\n";
    cout << "pop2: " << pop2(st) << "\n";

    return 0;
}
