#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::sort
using namespace std;

static vector<int> mergeKSortedArrays(vector<vector<int>> &input)
{
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to merge elements
    vector<int> result;

    // Push all elements from input arrays into min heap
    for (auto &arr : input)
    {
        for (int num : arr)
        {
            minHeap.push(num);
        }
    }

    // Extract elements from min heap to get sorted result
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main()
{
    // Example input
    vector<vector<int>> input = {
        {1, 5, 9},
        {45, 90},
        {2, 6, 78, 100, 234}};

    // Call the static method mergeKSortedArrays from Solution class
    vector<int> result = mergeKSortedArrays(input);

    // Print the sorted array
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
