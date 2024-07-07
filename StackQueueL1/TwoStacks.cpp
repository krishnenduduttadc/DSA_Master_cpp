#include <iostream>
#include <vector>
using namespace std;

class TwoStack {
private:
    vector<int> data;
    int tos1;  // Top of stack 1
    int tos2;  // Top of stack 2
public:
    TwoStack(int cap) {
        // Constructor to initialize the two stacks
        data.resize(cap);  // Resize the vector to given capacity
        tos1 = -1;  // Initialize top of stack 1 to -1
        tos2 = cap;  // Initialize top of stack 2 to cap (end of array)
    }

    int size1() {
        // Returns the size of stack 1
        return tos1 + 1;
    }

    int size2() {
        // Returns the size of stack 2
        return data.size() - tos2;
    }

    void push1(int val) {
        // Pushes an element onto stack 1
        if (tos2 == tos1 + 1) {
            cout << "Stack overflow\n";
        } else {
            tos1++;
            data[tos1] = val;
        }
    }

    void push2(int val) {
        // Pushes an element onto stack 2
        if (tos2 == tos1 + 1) {
            cout << "Stack overflow\n";
        } else {
            tos2--;
            data[tos2] = val;
        }
    }

    int pop1() {
        // Pops an element from stack 1
        if (size1() == 0) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            int val = data[tos1];
            tos1--;
            return val;
        }
    }

    int pop2() {
        // Pops an element from stack 2
        if (size2() == 0) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            int val = data[tos2];
            tos2++;
            return val;
        }
    }

    int top1() {
        // Returns the top element of stack 1
        if (size1() == 0) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            return data[tos1];
        }
    }

    int top2() {
        // Returns the top element of stack 2
        if (size2() == 0) {
            cout << "Stack underflow\n";
            return -1;
        } else {
            return data[tos2];
        }
    }
};

int main() {
    // Hardcoded example
    int capacity = 5;
    TwoStack st(capacity);

    // Perform operations
    st.push1(10);
    st.push1(20);
    st.push2(30);
    st.push2(40);
    st.push2(50);
    st.push1(60);

    cout << "top1: " << st.top1() << "\n";
    cout << "pop1: " << st.pop1() << "\n";
    cout << "top1: " << st.top1() << "\n";
    cout << "pop1: " << st.pop1() << "\n";
    cout << "top2: " << st.top2() << "\n";
    cout << "pop2: " << st.pop2() << "\n";
    cout << "top2: " << st.top2() << "\n";
    cout << "pop2: " << st.pop2() << "\n";
    cout << "top1: " << st.top1() << "\n";
    cout << "pop1: " << st.pop1() << "\n";
    cout << "top2: " << st.top2() << "\n";
    cout << "pop2: " << st.pop2() << "\n";

    return 0;
}
