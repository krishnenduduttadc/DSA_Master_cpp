#include <iostream>
#include <stack>
using namespace std;

void prevGreater(int arr[], int n) {
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[0]);

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        int pg = s.empty() ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}

void nextGreater(int arr[], int n) {
    stack<int> s;
    cout << -1 << " ";
    s.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        int ng = s.empty() ? -1 : s.top();
        cout << ng << " ";
        s.push(arr[i]);
    }
}

int main() {
    int arr[] = {15, 13, 12, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Previous greater elements: ";
    prevGreater(arr, n);
    cout << endl;

    cout << "Next greater elements: ";
    nextGreater(arr, n);
    cout << endl;

    return 0;
}
