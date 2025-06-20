#include <iostream>
#include <algorithm>
using namespace std;

static int countTriplets(int arr[], int n)
{
    sort(arr, arr + n);
    int count = 0;

    for (int i = n - 1; i >= 2; i--)
    {
        int left = 0, right = i - 1;

        while (left < right)
        {
            if (arr[left] + arr[right] == arr[i])
            {
                count++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return count;
}

int main()
{
    int n = 6;
    int arr[] = {1, 3, 5, 2, 7, 4};

    int result = countTriplets(arr, n);

    cout << "Number of triplets: " << result << endl;

    return 0;
}
