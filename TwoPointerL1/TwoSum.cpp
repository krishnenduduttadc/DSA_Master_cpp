#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    int num;
    int idx;
};

bool comparePairs(const Pair &a, const Pair &b)
{
    return a.num < b.num;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<Pair> arr;

    for (int i = 0; i < n; ++i)
    {
        Pair p;
        p.num = nums[i];
        p.idx = i;
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end(), comparePairs);

    int i = 0, j = n - 1;
    while (i < j)
    {
        int left = arr[i].num;
        int right = arr[j].num;
        int sum = left + right;

        if (sum == target)
        {
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

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

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
