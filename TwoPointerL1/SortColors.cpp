#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (nums[j] == 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
        else if (nums[j] == 1)
        {
            j++;
        }
        else
        {
            swap(nums[j], nums[k]);
            k--;
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    sortColors(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
