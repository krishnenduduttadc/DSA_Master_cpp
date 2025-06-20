#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= k; ++i) {
        pq.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < arr.size(); ++i) {
        arr[index++] = pq.top(); // Get the smallest element from the heap
        pq.pop(); // Remove the smallest element from the heap
        pq.push(arr[i]); // Insert the current element into the heap
    }

    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> arr = {3, 2, 4, 1, 6, 5, 7, 9, 8};
    int k = 3;

    sortKSortedArray(arr, k);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
