#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;
    stack<int> st;
    vector<int> nge(n);

    st.push(n-1);
    nge[n-1] = n;

    for (int i = n-2; i >= 0; i--) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }

        if (st.empty()) {
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }

        st.push(i);
    }

    for (int i = 0; i <= n-k; i++) {
        int j = i;
        while (nge[j] < i+k) {
            j = nge[j];
        }

        result.push_back(arr[j]);
    }

    return result;
}

int main() {
    // Hardcoded input
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMaximum(arr, k);

    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
