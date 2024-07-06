#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;

    // Push the first k elements into a stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Pop elements from the stack and enqueue them back into the queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Rotate the remaining elements in the queue
    int size = q.size();
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    // Create a queue and add some elements
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Define the value of k
    int k = 3;

    // Call the modifyQueue function and store the result
    queue<int> result = modifyQueue(q, k);

    // Print the result queue
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
