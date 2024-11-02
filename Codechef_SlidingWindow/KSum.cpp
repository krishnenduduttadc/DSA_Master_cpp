#include <bits/stdc++.h>

using namespace std;

int maxSumKElements(const vector<int>& arr, int k) {
    int i = 0;
    int n = arr.size();
    int csum = 0;

    for (int i = 0; i < k; i++) {
        csum += arr[i];
    }
    int osum = csum;
    for (int i = 0; i < k; i++) {
        int inclu = arr[n-1-i];
        int exclu = arr[k-1-i];
        csum = csum - exclu + inclu;
        osum = max(csum, osum);
    }

    return osum;
}

int main() {
    vector<int> arr = {4, 2, 1, 5, 1}; // Hardcoded array
    int k = 3; // Hardcoded value for k

    cout << maxSumKElements(arr, k) << endl;

    return 0;
}
