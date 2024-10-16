#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > pre(n, 0), suf(n, 0);
    vector < int > v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
        if (i == 0) pre[i] = v1[i];
        else pre[i] = __gcd(v1[i], pre[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) suf[i] = v1[i];
        else suf[i] = __gcd(v1[i], suf[i + 1]);
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
    cout << fans << "\n";

    // your code goes here

}

/*
4
4 3 2 6
*/