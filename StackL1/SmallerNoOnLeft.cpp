#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> leftSmaller(int n, int a[]) {
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[i] < a[st.top()]) {
            int idx = st.top();
            ans[idx] = a[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        int idx = st.top();
        ans[idx] = -1;
        st.pop();
    }

    return ans;
}

int main() {
    int arr[] = {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = leftSmaller(n, arr);

    cout << "Resulting list:" << endl;
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
