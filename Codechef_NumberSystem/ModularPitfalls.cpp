#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long computeSumOfSquares(vector<int>& arr) {
    long long sum = 0;
    for (int num : arr) {
        sum = (sum + (num * 1LL * num) % MOD) % MOD;
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            arr[j] = arr[j] % MOD;
        }

        long long result = computeSumOfSquares(arr);
        cout << result << endl;
    }

    return 0;
}



/*
2
5
2 34 4 56 76
3
23 7 21

*/