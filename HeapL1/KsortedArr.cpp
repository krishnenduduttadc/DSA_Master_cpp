#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min heap

    for (int i = 0; i <= k; ++i) {
        pq.push(arr[i]);
    }

    int index = 0;

    for (int i = k + 1; i < arr.size(); ++i) {
        arr[index++] = pq.top(); // Get the smallest element from the heap
        pq.pop(); // Remove the smallest element from the heap
        pq.push(arr[i]); // Push the current element into the heap
    }

    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {7, 8, 9, 19, 18};
    int k = 3;
    sortKSortedArray(arr, k);
    return 0;
}
