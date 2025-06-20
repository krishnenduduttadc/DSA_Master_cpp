#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> input)
{
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to merge elements
    vector<int> result;

    for (auto arr : input)
    {
        for (int num : arr)
        {
            minHeap.push(num);
        }
    }

    
    while (!minHeap.empty())
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main()
{
    vector<vector<int>> input = {
        {1, 5, 9},
        {45, 90},
        {2, 6, 78, 100, 234}};

    vector<int> result = mergeKSortedArrays(input);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
