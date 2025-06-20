#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void klargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++) {
        if (pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << "K largest elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    vector<int> arr = {5, 15, 10, 20, 8, 25, 18};
    int k = 3;

    klargest(arr, k);

    return 0;
}
