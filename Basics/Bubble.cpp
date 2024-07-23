#include <iostream>
using namespace std;
int main()
{
    int arr[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout <<" "<< arr[i];
    }
}