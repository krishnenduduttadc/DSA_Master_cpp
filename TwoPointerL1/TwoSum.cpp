#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TwoSum
{
public:
    struct Pair
    {
        int num;
        int idx;

        Pair(int num, int idx)
        {
            this->num = num;
            this->idx = idx;
        }

        // Define comparison operator for sorting
        bool operator<(const Pair &other) const
        {
            return num < other.num;
        }
    };

    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<Pair> arr;

        // Populate arr with pairs (num, index)
        for (int i = 0; i < n; ++i)
        {
            arr.push_back(Pair(nums[i], i));
        }

        // Sort arr based on num
        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;
        while (i < j)
        {
            int left = arr[i].num;
            int right = arr[j].num;
            int sum = left + right;

            if (sum == target)
            {
                // Return indices in sorted order
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
};

int main()
{
    // Hardcoded input vector and target
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Create an instance of the TwoSum class
    TwoSum solution;

    // Call twoSum to find indices of the two numbers that add up to target
    vector<int> result = solution.twoSum(nums, target);

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
