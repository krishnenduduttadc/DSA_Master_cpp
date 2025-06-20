#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void stockSpan(vector<int>& arr) {
    stack<int> s;
    s.push(0); // Push index of the first element

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        int span = s.empty() ? (i + 1) : (i - s.top());
        cout << span << " ";
        s.push(i);
    }
}

int main() {
    vector<int> arr = {15, 13, 12, 14, 15};
    stockSpan(arr);
    cout << endl;

    return 0;
}
