#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define Pair struct
struct Pair
{
    int num;
    int idx;
};

// Comparison function for sorting
bool comparePairs(const Pair &a, const Pair &b)
{
    return a.num < b.num;
}

// Function that performs the two sum logic
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<Pair> arr;

    // Populate arr with pairs (num, index)
    for (int i = 0; i < n; ++i)
    {
        Pair p;
        p.num = nums[i];
        p.idx = i;
        arr.push_back(p);
    }

    // Sort arr based on num
    sort(arr.begin(), arr.end(), comparePairs);

    int i = 0, j = n - 1;
    while (i < j)
    {
        int left = arr[i].num;
        int right = arr[j].num;
        int sum = left + right;

        if (sum == target)
        {
            // Return indices
            return {arr[i].idx, arr[j].idx};
        }
        else if (sum < target)
        {
            ++i;
        }
        else
        {
            --j;
        }
    }

    // If no pair found, return empty vector
    return {};
}

int main()
{
    // Hardcoded input vector and target
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call twoSum to find indices of the two numbers that add up to target
    vector<int> result = twoSum(nums, target);

    // Print the indices
    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No valid indices found." << endl;
    }

    return 0;
}
