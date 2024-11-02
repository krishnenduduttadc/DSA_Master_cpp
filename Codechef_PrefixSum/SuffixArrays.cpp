#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 4; // Hardcoded size of the array
    vector<int> v1 = {4, 3, 2, 6}; // Hardcoded array values
    vector<int> pre(n, 0), suf(n, 0);

    for (int i = 0; i < n; i++) {
        if (i == 0) 
            pre[i] = v1[i];
        else 
            pre[i] = __gcd(v1[i], pre[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) 
            suf[i] = v1[i];
        else 
            suf[i] = __gcd(v1[i], suf[i + 1]);
    }

    int fans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fans = max(fans, suf[i + 1]);
        }
        else if (i == n - 1) {
            fans = max(fans, pre[i - 1]);
        }
        else {
            fans = max(fans, __gcd(pre[i - 1], suf[i + 1]));
        }
    }
    cout << fans << "\n"; // Output the maximum GCD value

    return 0;
}
