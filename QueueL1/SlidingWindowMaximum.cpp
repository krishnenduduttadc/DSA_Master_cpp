#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> deque;

    for (int i = 0; i < k; i++)
    {
        while (!deque.empty() && nums[deque.back()] <= nums[i])
        {
            deque.pop_back();
        }
        deque.push_back(i);
    }
    ans.push_back(nums[deque.front()]);

    for (int i = k; i < n; i++)
    {
        if (!deque.empty() && deque.front() == i - k)
        {
            deque.pop_front();
        }
        while (!deque.empty() && nums[deque.back()] <= nums[i])
        {
            deque.pop_back();
        }
        deque.push_back(i);
        ans.push_back(nums[deque.front()]);
    }

    return ans;
}

int main()
{

    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(nums1, k1);
    cout << "Max sliding window for nums1 and k=" << k1 << ": ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
