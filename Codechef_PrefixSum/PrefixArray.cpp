#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input values
    int len = 4;
    vector<int> arr = {5, 3, 3, 13}; // Hardcoded array values

    vector<int> pre(len, 0);
    for (int i = 0; i < len; i++) {
        if (i != 0) {
            pre[i] += pre[i - 1];
        }
        pre[i] += arr[i];
    }

    for (auto e : pre) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}
