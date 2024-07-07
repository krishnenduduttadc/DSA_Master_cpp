#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void display(const vector<int>& a) {
    for (int val : a) {
        cout << val << "\n";
    }
}

vector<int> solve(const vector<int>& arr) {
    int n = arr.size();
    vector<int> span(n, 0);
    stack<int> st;
    st.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        span[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    return span;
}

int main() {
    // Example input
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = solve(arr);

    // Display the result
    display(span);

    return 0;
}
