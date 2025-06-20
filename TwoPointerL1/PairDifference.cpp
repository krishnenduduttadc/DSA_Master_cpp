#include <iostream>
#include <algorithm> // for sorting
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size); // Sort the array

    int i = 0, j = 1;
    while (i < size && j < size)
    {
        if (i != j && arr[j] - arr[i] == n)
        {
            return true;
        }
        else if (arr[j] - arr[i] > n)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 8, 30, 40, 100};
    int n = 60;
    bool result = findPair(arr, sizeof(arr) / sizeof(arr[0]), n);
    cout << "Pair with difference " << n << " exists: " << boolalpha << result << endl;

    return 0;
}
