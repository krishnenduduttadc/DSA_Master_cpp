#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

struct MaxFreqStack {
    unordered_map<int, stack<int>> st;
    unordered_map<int, int> fmap;
    int maxfreq;
};

// Initialize the stack
void init(MaxFreqStack &mfs) {
    mfs.maxfreq = 0;
}

// Push value to stack
void push(MaxFreqStack &mfs, int val) {
    int f = ++mfs.fmap[val];
    mfs.st[f].push(val);
    mfs.maxfreq = max(mfs.maxfreq, f);
}

// Pop and return the most frequent element
int pop(MaxFreqStack &mfs) {
    int val = mfs.st[mfs.maxfreq].top();
    mfs.st[mfs.maxfreq].pop();

    if (mfs.st[mfs.maxfreq].empty()) {
        mfs.st.erase(mfs.maxfreq);
        mfs.maxfreq--;
    }

    mfs.fmap[val]--;
    return val;
}

int main() {
    MaxFreqStack freqStack;
    init(freqStack);

    push(freqStack, 5);
    push(freqStack, 7);
    push(freqStack, 5);
    push(freqStack, 7);
    push(freqStack, 4);
    push(freqStack, 5);

    cout << pop(freqStack) << endl; // Should print 5
    cout << pop(freqStack) << endl; // Should print 7
    cout << pop(freqStack) << endl; // Should print 5
    cout << pop(freqStack) << endl; // Should print 4

    return 0;
}
