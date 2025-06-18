#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> getMinimums(vector<int> nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    if (k > n)
        return ans;

    deque<int> deque;

    // Process the first window of size k
    for (int i = 0; i < k; i++)
    {
        while (!deque.empty() && deque.back() > nums[i])
        {
            deque.pop_back();
        }
        deque.push_back(nums[i]);
    }
    ans.push_back(deque.front()); // Store the minimum for the first window

    // Process the rest of the elements
    for (int i = k; i < n; i++)
    {
        if (deque.front() == nums[i - k])
        {
            deque.pop_front(); // Remove the element that is no longer in the window
        }
        while (!deque.empty() && deque.back() > nums[i])
        {
            deque.pop_back(); // Maintain the deque in descending order
        }
        deque.push_back(nums[i]);
        ans.push_back(deque.front()); // Store the minimum for the current window
    }

    return ans;
}

int main()
{

    // Test case 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = getMinimums(nums1, k1);
    cout << "Minimums for nums1 and k=" << k1 << ": ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
