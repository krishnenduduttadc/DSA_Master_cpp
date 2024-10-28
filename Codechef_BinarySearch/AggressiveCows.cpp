#include <bits/stdc++.h>

using namespace std;

bool check(int arr[], int d, int n, int c)
{
    int cows = c;
    cows--;
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - prev >= d)
        {
            cows--;
            prev = arr[i];
        }
        if (cows == 0) break;
    }
    if (cows <= 0) return true;
    return false;
}

int main() {
    int n = 5, c = 3;
    int arr[] = {1, 2, 8, 4, 9};
    sort(arr, arr + n);

    int left = 0;
    int right = arr[n - 1] - arr[0];
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(arr, mid, n, c)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
