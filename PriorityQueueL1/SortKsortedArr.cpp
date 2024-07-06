#include <iostream>
#include <queue>
using namespace std;

void sort(int arr[], int n, int k) {
    // Create a min-heap (priority_queue) to store the first k+1 elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert the first k+1 elements into the min-heap
    for (int i = 0; i <= k && i < n; i++) {
        pq.push(arr[i]);
    }

    // Process the remaining elements
    int index = 0;
    for (int i = k + 1; i < n; i++) {
        // Pop the smallest element from the min-heap and store it in arr
        arr[index++] = pq.top();
        pq.pop();

        // Push the current element into the min-heap
        pq.push(arr[i]);
    }

    // Pop and store the remaining elements from the min-heap
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main() {
    int arr[] = {2, 4, 1, 9, 6, 8};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n, k);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
