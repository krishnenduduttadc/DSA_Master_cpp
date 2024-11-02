#include <bits/stdc++.h>
using namespace std;

long long countPairsLessThanX(vector<int>& arr, int x) {
    long long count = 0;
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        if (arr[left] + arr[right] < x) {
            count += (right - left);
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Hardcoded array
    int x = 7; // Hardcoded value of x

    cout << countPairsLessThanX(arr, x) << endl; // Output the result

    return 0;
}
