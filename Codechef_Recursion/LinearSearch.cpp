#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int n, int x) {
    if (n == arr.size()) {
        return -1;
    }
    if (arr[n] == x) {
        return n;
    }
    return linearSearch(arr, n + 1, x);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << linearSearch(arr, 0, x) << endl;
    return 0;
}


/*
5 9
1 4 9 2 8

*/