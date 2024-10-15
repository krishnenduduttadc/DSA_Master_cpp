#include <bits/stdc++.h>
using namespace std;

int n, d, a[100010];

int main() {
    cin>>n>>d;

    for (int i = 1; i <= n; i++)
        cin>>a[i];

    sort (a + 1, a + 1 + n);

    int pos = 1;
    int res = 0;

    while (pos < n) {
        if (abs(a[pos] - a[pos + 1]) <= d) {
            res ++;
            pos += 2;
        }
        else pos ++;
    }

    cout<<res<<endl;

    return 0;
}

/*
5 2
1
3
3
9
4
*/