#include <iostream>
#include <queue>
using namespace std;

void sort(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= k && i < n; i++) {
        pq.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

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

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
