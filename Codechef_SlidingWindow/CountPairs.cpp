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
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    cout << countPairsLessThanX(arr, x) << endl;
    return 0;
}

/*
5
1 2 3 4 5
7
*/