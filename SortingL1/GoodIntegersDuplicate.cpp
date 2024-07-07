#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GoodIntegers(int arr[], int n) {
    sort(arr, arr + n); // Sort the array

    int ans = 0;
    int lessCount = 0;

    if (arr[0] == 0) {
        ans++;
    }

    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[i - 1]) {
            lessCount = i;
        }

        if (arr[i] == lessCount) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int arr[] = {0, 1, 5, 7, 8, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << GoodIntegers(arr, n) << endl;

    return 0;
}
