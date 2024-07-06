#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallest(vector<int>& arr, int l, int r, int k) {
    priority_queue<int> pq;

    for (int i = 0; i <= r; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main() {
    // Hardcoded input array
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int l = 0;
    int r = arr.size() - 1;

    // Call the kthSmallest function and store the result
    int result = kthSmallest(arr, l, r, k);

    // Print the result
    cout << "The " << k << "rd smallest element is " << result << endl;

    return 0;
}
