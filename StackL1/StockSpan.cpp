#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void stockSpan(vector<int>& arr) {
    stack<int> s;
    s.push(0); // Push index of the first element

    for (int i = 0; i < arr.size(); i++) {
        // Pop elements from stack while the current price is greater than the price of the element at the top of the stack
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        
        // Calculate span (i - index at top of stack after popping or i + 1 if stack is empty)
        int span = s.empty() ? (i + 1) : (i - s.top());
        
        // Print the span
        cout << span << " ";
        
        // Push the current index onto the stack
        s.push(i);
    }
}

int main() {
    // Test case: array of stock prices
    vector<int> arr = {15, 13, 12, 14, 15};
    stockSpan(arr);
    cout << endl;

    return 0;
}
