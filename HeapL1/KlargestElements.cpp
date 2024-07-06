#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void klargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert the first k elements into the min heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // For each element from k to end of array, check if it's larger than the smallest in the heap
    for (int i = k; i < arr.size(); i++) {
        if (pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Print the k largest elements
    cout << "K largest elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    // Hardcoded input array
    vector<int> arr = {5, 15, 10, 20, 8, 25, 18};
    int k = 3;

    // Call the klargest function to find and print the k largest elements
    klargest(arr, k);

    return 0;
}
