#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int kthLargest(int n, vector<int> input, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(input[i]);
    }

    for (int j = 0; j < k - 1; j++)
    {
        pq.pop();
    }

    return pq.top();
}

int main()
{
    vector<int> arr = {2, 4, 1, 9, 6, 8};
    int k = 3;

    int result = kthLargest(arr.size(), arr, k);

    cout << "Kth largest element: " << result << endl;

    return 0;
}
