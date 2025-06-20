#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;

    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int size = q.size();
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    queue<int> result = modifyQueue(q, k);

    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
