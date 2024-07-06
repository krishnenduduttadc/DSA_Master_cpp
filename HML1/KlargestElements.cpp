#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(int n, vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    for (int i = 0; i < arr.size(); ++i) {
        if (i < k) {
            pq.push(arr[i]);
        } else {
            if (arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    for (int j = result.size() - 1; j >= 0; --j) {
        cout << result[j] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> num = {44, -5, -2, 41, 12, 19, 21, -6};
    int k = 2;
    solve(num.size(), num, k);

    return 0;
}
