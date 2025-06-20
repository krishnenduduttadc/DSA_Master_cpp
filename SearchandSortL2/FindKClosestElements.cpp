#include <iostream>
#include <vector>
#include <cstdlib>   // for abs function
#include <algorithm> // for sort function
using namespace std;

static vector<int> findClosest(vector<int> &arr, int k, int x)
{
    int lo = 0;
    int hi = arr.size() - 1;

    while (hi - lo >= k)
    {
        if (abs(arr[lo] - x) > abs(arr[hi] - x))
        {
            lo++;
        }
        else
        {
            hi--;
        }
    }

    vector<int> result(arr.begin() + lo, arr.begin() + lo + k);

    return result;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int k = 3;
    int x = 45;

    vector<int> ans = findClosest(arr, k, x);

    cout << "Closest elements to " << x << ": ";
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
