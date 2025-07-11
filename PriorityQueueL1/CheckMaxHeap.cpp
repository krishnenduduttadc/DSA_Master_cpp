#include <iostream>
#include <vector>
using namespace std;

static bool checkMaxHeap(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int pIndex = i;
        int lIndex = 2 * i + 1;
        int rIndex = 2 * i + 2;

        if (lIndex < arr.size() && arr[pIndex] < arr[lIndex])
        {
            return false;
        }

        if (rIndex < arr.size() && arr[pIndex] < arr[rIndex])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {42, 20, 18, 6, 14, 11, 9, 4};

    bool result = checkMaxHeap(arr);

    cout << boolalpha << result << endl;

    return 0;
}
