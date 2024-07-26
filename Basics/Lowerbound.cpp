#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {5, 6, 4, 8, 2, 1};
    int n = 6;
    int x = 8;
    auto k = lower_bound(arr, arr + n, x)-arr;
    if (arr[k] == x)
    {
        cout << k;
    }
}