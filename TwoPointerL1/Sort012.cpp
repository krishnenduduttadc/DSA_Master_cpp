#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int> &arr)
{
    int i = 0, j = 0, k = arr.size() - 1;
    while (j <= k)
    {
        if (arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] == 1)
        {
            j++;
        }
        else
        {
            swap(arr[j], arr[k]);
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
    // Hardcoded input vector
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2, 1};

    // Print the original array
    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Create an instance of Sort012 class

    // Call sort012 to sort the array
    sort012(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
