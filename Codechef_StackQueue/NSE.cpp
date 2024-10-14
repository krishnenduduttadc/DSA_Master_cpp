#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

std::vector<int> nextSmallestElement(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> result(n, -1); // Initialize result with -1 for elements with no smaller element
    std::stack<int> s; // Stack to store indices

    for (int i = n - 1; i >= 0; --i) { // Iterate from right to left
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        if(s.size()!=0) {
            result[i] = arr[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> result = nextSmallestElement(arr);
    for (auto e : result) {
        cout << e << " ";
    }
    return 0;
}


/*
5
1 3 5 1 3
*/