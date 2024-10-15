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
    int n, c;
    cin >> n >> c;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); // Sort the stall positions

    // Binary search for the maximum minimum distance
    int left = 0; // Minimum possible distance
    int right = arr[n - 1] - arr[0]; // Maximum possible distance
    int result = 0; // To store the result

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid distance

        // Check if it's possible to place cows with at least mid distance
        if (check(arr, mid, n, c)) {
            result = mid; // Update result to mid since it's a valid distance
            left = mid + 1; // Try for a larger distance
        } else {
            right = mid - 1; // Try for a smaller distance
        }
    }

    cout << result << endl; // Output the largest minimum distance found
    return 0;



}

/*

5 3
1 2 8 4 9
*/