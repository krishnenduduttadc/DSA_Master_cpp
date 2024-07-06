#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class MaxFrequencyStack {
private:
    unordered_map<int, stack<int>> st;
    unordered_map<int, int> fmap;
    int maxfreq;

public:
    MaxFrequencyStack() {
        maxfreq = 0;
    }

    void push(int val) {
        int f = fmap[val]++;
        st[f].push(val);
        maxfreq = max(maxfreq, f);
    }

    int pop() {
        int val = st[maxfreq].top();
        st[maxfreq].pop();
        if (st[maxfreq].empty()) {
            st.erase(maxfreq);
            maxfreq--;
        }
        fmap[val]--;
        return val;
    }
};

int main() {
    MaxFrequencyStack freqStack;

    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(4);
    freqStack.push(5);

    cout << freqStack.pop() << endl; // Should print 5
    cout << freqStack.pop() << endl; // Should print 7
    cout << freqStack.pop() << endl; // Should print 5
    cout << freqStack.pop() << endl; // Should print 4

    return 0;
}
