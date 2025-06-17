#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int kthLargest(int n, vector<int> &input, int k)
{
    // Use a priority queue (max heap) to find the kth largest element
    priority_queue<int> pq;

    // Insert all elements into the max heap
    for (int i = 0; i < n; i++)
    {
        pq.push(input[i]);
    }

    // Remove the top k-1 elements to get the kth largest element
    for (int j = 0; j < k - 1; j++)
    {
        pq.pop();
    }

    // Return the kth largest element
    return pq.top();
}

int main()
{
    // Example input
    vector<int> arr = {2, 4, 1, 9, 6, 8};
    int k = 3;

    // Call the static method kthLargest from KthLargest class
    int result = kthLargest(arr.size(), arr, k);

    // Print the result
    cout << "Kth largest element: " << result << endl;

    return 0;
}
