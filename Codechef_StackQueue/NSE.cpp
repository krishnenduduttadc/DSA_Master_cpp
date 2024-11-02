#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to find the next smallest element for each element in the array
vector<int> nextSmallestElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1 for elements with no smaller element
    stack<int> s; // Stack to store indices

    // Iterate from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack that are greater than or equal to the current element
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        // If stack is not empty, the top element is the next smallest
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }
        // Push the current index onto the stack
        s.push(i);
    }

    return result;
}

int main() {
    // Hardcoded input
    int n = 5; // Size of the array
    vector<int> arr = {1, 3, 5, 1, 3}; // The array itself

    // Find the next smallest element for each element
    vector<int> result = nextSmallestElement(arr);

    // Output the result
    for (auto e : result) {
        cout << e << " "; // Print each result
    }
    cout << endl;

    return 0;
}
