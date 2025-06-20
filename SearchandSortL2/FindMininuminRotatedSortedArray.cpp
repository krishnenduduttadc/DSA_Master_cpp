#include <iostream>
#include <vector>
using namespace std;

static int findMinimum(vector<int> &arr)
{
    int lo = 0;
    int hi = arr.size() - 1;

    if (arr[lo] <= arr[hi])
    {
        return arr[0];
    }

    while (lo <= hi)
    {
        if (arr[lo] <= arr[hi])
        {
            return arr[lo];
        }

        int mid = lo + (hi - lo) / 2;
        int next = (mid + 1) % arr.size(); // Calculate next index considering wrap around

        if (arr[mid] <= arr[next] && arr[mid] <= arr[mid - 1])
        {
            return arr[mid];
        }
        else if (arr[mid] <= arr[hi])
        {
            hi = mid - 1;
        }
        else if (arr[lo] <= arr[mid])
        {
            lo = mid + 1;
        }
    }

    return -1; // This line should never be reached if the input is valid
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 0, 1, 3};

    int ans = findMinimum(arr);

    cout << "Minimum element: " << ans << endl;

    return 0;
}
