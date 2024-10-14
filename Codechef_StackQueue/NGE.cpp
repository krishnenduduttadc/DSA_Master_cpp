#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> stack;

    // Initialize the NGE array
    vector<int> nge(n, -1);

    // Iterating the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop till the top element is smaller than current
        while (!stack.empty() && stack.top() < arr[i]) {
            stack.pop();
        }

        if (!stack.empty()) {
            nge[i] = stack.top();
        } else {
            nge[i] = -1;
        }

        // Push the current element to stack
        stack.push(arr[i]);
    }

    // Print the NGE array
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;
}


/*
4 
4 5 2 25
*/